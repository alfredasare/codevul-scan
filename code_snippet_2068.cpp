static int addAggInfoFunc(sqlite3 *db, AggInfo *pInfo){
  int i = sqlite3ArraySize(pInfo->aFunc);
  if (i >= SQLITE_MAX_TYPE) {
    return SQLITE_ERROR;
  }
  pInfo->aFunc = sqlite3ArrayAllocate(
      db,
      pInfo->aFunc,
      sizeof(pInfo->aFunc[0]),
      &pInfo->nFunc,
      &i
  );
  return i;
}