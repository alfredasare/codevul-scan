static XHCIEPContext *xhci_alloc_epctx(XHCIState *xhci,
                                       unsigned int slotid,
                                       unsigned int epid)
{
    XHCIEPContext *epctx;
    int i;

    epctx = g_new0(XHCIEPContext, 1);

    epctx->xhci = xhci;
    epctx->slotid = slotid;
    epctx->epid = epid;

    memset(epctx->transfers, 0, sizeof(epctx->transfers[0]) * ARRAY_SIZE(epctx->transfers));

    epctx->kick_timer = NULL;

    return epctx;
}