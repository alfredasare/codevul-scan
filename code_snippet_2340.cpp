XRecordUnregisterClients(Display *dpy, XRecordContext context,
                         XRecordClientSpec *clients, int nclients)
{
    XExtDisplayInfo *info = find_display (dpy);
    register xRecordUnregisterClientsReq 	*req;
    int			clen = 4 * (nclients > MAX_NCLIENTS ? MAX_NCLIENTS : nclients);

    XRecordCheckExtension (dpy, info, 0);
    LockDisplay(dpy);
    GetReq(RecordUnregisterClients, req);

    req->reqType = info->codes->major_opcode;
    req->recordReqType = X_RecordUnregisterClients;
    req->context = context;
    req->length += (nclients > MAX_NCLIENTS ? MAX_NCLIENTS : nclients);
    req->nClients = (nclients > MAX_NCLIENTS ? MAX_NCLIENTS : nclients);

    Data32(dpy, (long *)clients, clen);

    UnlockDisplay(dpy);
    SyncHandle();
    return 1;
}