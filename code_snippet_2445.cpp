AirPDcap_SEC_ASSOCIATION_ID *AirPDcapGetSaPtr(PAIRPDCAP_CONTEXT ctx, AIRPDCAP_SEC_ASSOCIATION_ID *id)
{
    int sa_index;

    /* search for a cached Security Association for supplied BSSID and STA MAC  */
    if ((sa_index = AirPDcapGetSa(ctx, id)) == -1) {
        /* create a new Security Association if it doesn't currently exist      */
        if ((sa_index = AirPDcapStoreSa(ctx, id)) == -1) {
            return NULL;
        }
    }

    // Validate sa_index to avoid null pointer dereference
    if (sa_index >= 0 && sa_index < MAX_SA_COUNT) {
        /* get the Security Association structure   */
        return &ctx->sa[sa_index];
    } else {
        // Handle the error or log an error message before returning NULL
        // This will prevent the null pointer dereference
        fprintf(stderr, "Error: Invalid sa_index: %d\n", sa_index);
        return NULL;
    }
}