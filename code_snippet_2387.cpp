SPR\_ListEntries(struct rx\_call \*call, afs\_int32 flag, afs\_int32 startindex,
prentries \*bulkentries, afs\_int32 \*nextstartindex)
{
afs\_int32 code;
afs\_int32 cid = call ? call->cid : ANONYMOUSID;

code = listEntries(call, flag, startindex, bulkentries, nextstartindex, &cid);
osi\_auditU(call, PTS\_LstEntsEvent, code, AUD\_LONG, flag, AUD\_END);
ViceLog(125, ("PTS\_ListEntries: code %d cid %d flag %d\n", code, cid, flag));
return code;
}