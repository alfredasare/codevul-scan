static void codeDeferredSeek(
  WhereInfo *pWInfo,              /* Where clause context */
  Index *pIdx,                    /* Index scan is using */
  int iCur,                       /* Cursor for IPK b-tree */
  int iIdxCur                     /* Index cursor */
){
  Parse *pParse = pWInfo->pParse; /* Parse context */
  Vdbe *v = pParse->pVdbe;        /* Vdbe to generate code within */

  assert( iIdxCur>0 );
  assert( pIdx->aiColumn[pIdx->nColumn-1]==-1 );
  
  sqlite3VdbeAddOp3(v, OP_Seek, iIdxCur, 0, iCur);
  if( (pWInfo->wctrlFlags & WHERE_OR_SUBCLAUSE)
   && DbMaskAllZero(sqlite3ParseToplevel(pParse)->writeMask)
  ){
    int i;
    Table *pTab = pIdx->pTable;
    int *ai = (int*)sqlite3DbMallocZero(pParse->db, sizeof(int)*(pTab->nCol+1));
    if( ai ){
      ai[0] = pTab->nCol;
      for(i=0; i<pIdx->nColumn-1; i++){
        assert( pIdx->aiColumn[i]<pTab->nCol );
        if( pIdx->aiColumn[i]>=0 ) ai[pIdx->aiColumn[i]+1] = i+1;
      }
      sqlite3VdbeChangeP4(v, -1, (char*)ai, P4_INTARRAY);
    }
  }
}
