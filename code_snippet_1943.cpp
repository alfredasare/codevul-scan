static int addAggInfoFunc(sqlite3 *db, AggInfo *pInfo){
    int i;
    pInfo->aFunc = sqlite3_malloc((int)sizeof(pInfo->aFunc[0]) * pInfo->nFunc);
    if (pInfo->aFunc == NULL) {
        // Handle allocation failure
    }
    pInfo->nFunc = (int)i;
    return i;
}