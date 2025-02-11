long kvmppc_alloc_lpid(void)
{
    long lpid;
    unsigned int nr_lpids = KVMPPC_NR_LPIDS; 

    do {
        lpid = find_first_zero_bit(lpid_inuse, nr_lpids);
        if (lpid >= nr_lpids) {
            pr_err("%s: No LPIDs free\n", __func__);
            return -ENOMEM;
        }
    } while (test_and_set_bit((unsigned long)lpid, lpid_inuse)); 

    return lpid;
}