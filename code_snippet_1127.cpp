BOOLEAN btm_sec_are_all_trusted(UINT32 p_mask[])
{
    UINT32 trusted_inx;
    UINT32 mask_size = sizeof(p_mask) / sizeof(p_mask[0]);

    for (trusted_inx = 0; trusted_inx < mask_size; trusted_inx++)
    {
        if (p_mask[trusted_inx]!= BTM_SEC_TRUST_ALL)
            return FALSE;
    }

    return TRUE;
}