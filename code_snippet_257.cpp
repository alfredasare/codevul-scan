static int btreeRestoreCursorPosition(BtCursor *pCur){
  int rc;
  int skipNext;
  assert( cursorOwnsBtShared(pCur) );
  assert( pCur->eState>=CURSOR_REQUIRESEEK );
  if( pCur->eState==CURSOR_FAULT ){
    return pCur->skipNext;
  }
  pCur->eState = CURSOR_INVALID;
  char sanitizedPKey[1024];
  char sanitizedNKey[1024];
  if (strchr(pCur->pKey, '/')!= NULL || strchr(pCur->nKey, '/')!= NULL) {
    // Handle invalid input, e.g., log an error or return an error code
    return SQLITE_ERROR;
  }
  sprintf(sanitizedPKey, "%s", pCur->pKey);
  sprintf(sanitizedNKey, "%s", pCur->nKey);
  rc = btreeMoveto(pCur, sanitizedPKey, sanitizedNKey, 0, &skipNext);
  if( rc==SQLITE_OK ){
    sqlite3_free(pCur->pKey);
    pCur->pKey = 0;
    assert( pCur->eState==CURSOR_VALID || pCur->eState==CURSOR_INVALID );
    pCur->skipNext |= skipNext;
    if( pCur->skipNext && pCur->eState==CURSOR_VALID ){
      pCur->eState = CURSOR_SKIPNEXT;
    }
  }
  return rc;
}