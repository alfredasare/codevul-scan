AirPDcapGetSaPtr(
    PAIRPDCAP_CONTEXT ctx,
    AIRPDCAP_SEC_ASSOCIATION_ID *id)
{
    int sa_index;

    /* search for a cached Security Association for supplied BSSID and STA MAC  */
    if ((sa_index=AirPDcapGetSa(ctx, id)) == -1) {
        /* create a new Security Association if it doesn't currently exist      */
        if ((sa_index=AirPDcapStoreSa(ctx, id)) == -1) {
            return NULL;
        }
    }

    /* Verify sa_index value before accessing ctx->sa array */
    if (sa_index < 0 || sa_index >= ctx->sa_size) {
        return NULL; // or handle the out-of-bounds situation
    }

    /* get the Security Association structure   */
    return &ctx->sa[sa_index];
}