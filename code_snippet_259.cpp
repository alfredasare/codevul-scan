static int btreeRestoreCursorPosition(BtCursor \*pCur){
int rc;
int skipNext;
assert(cursorOwnsBtShared(pCur));
assert(pCur->eState>=CURSOR\_REQUIRESEEK);
if(pCur->eState==CURSOR\_FAULT){
return pCur->skipNext;
}
pCur->eState = CURSOR\_INVALID;
rc = btreeMoveto(pCur, pCur->pKey, MIN(pCur->nKey, sizeof(pCur->pKey)), 0, &skipNext);
if(rc==SQLITE\_OK){
sqlite3\_free(pCur->pKey[pCur->nKey]);
pCur->pKey[pCur->nKey] = 0;
assert(pCur->eState==CURSOR\_VALID || pCur->eState==CURSOR\_INVALID);
pCur->skipNext |= skipNext;
if(pCur->skipNext && pCur->eState==CURSOR\_VALID){
pCur->eState = CURSOR\_SKIPNEXT;
}
}
return rc;
}