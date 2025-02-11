static void addModuleArgument(sqlite3 *db, Table *pTable, char *zArg){
  size_t nBytes = sizeof(char *) * (pTable->nModuleArg + 2);
  char **azModuleArg = (char **)sqlite3_malloc(nBytes);
  if( azModuleArg == NULL ){
    sqlite3DbFree(db, zArg);
  } else {
    int i = pTable->nModuleArg++;
    azModuleArg[i] = zArg;
    azModuleArg[i+1] = 0;
    pTable->azModuleArg = azModuleArg;
  }
}