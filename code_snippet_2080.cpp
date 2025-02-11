int wvlan_uil_connect(struct uilreq *urq, struct wl_private *lp)
{
    int result = 0;
    /*------------------------------------------------------------------------*/

    DBG_FUNC("wvlan_uil_connect");
    DBG_ENTER(DbgInfo);

    if (!(lp->flags & WVLAN2_UIL_CONNECTED)) {
        if (!lp->hcfCtxInitialized) {
            lp->hcfCtx = kzalloc(sizeof(struct hcf_context), GFP_KERNEL);
            if (!lp->hcfCtx) {
                DBG_ERROR(DbgInfo, "Failed to allocate memory for hcfCtx\n");
                return -ENOMEM;
            }
            lp->hcfCtxInitialized = true;
        }

        lp->flags |= WVLAN2_UIL_CONNECTED;
        if (lp->hcfCtx) {
            urq->hcfCtx = lp->hcfCtx;
            urq->result = UIL_SUCCESS;
        } else {
            DBG_ERROR(DbgInfo, "hcfCtx is not initialized\n");
            return -EINVAL;
        }
    } else {
        DBG_WARNING(DbgInfo, "UIL_ERR_IN_USE\n");
        urq->result = UIL_ERR_IN_USE;
    }

    DBG_LEAVE(DbgInfo);
    return result;
}