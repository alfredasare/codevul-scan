static UINT16 GetDigestSize(TPM_ALG_ID authHash)
{
    // Add input validation
    if (authHash >= TPM_ALG_MAX || authHash < TPM_ALG_NONE)
    {
        // Handle invalid input appropriately, such as returning an error code or logging an error message.
        return 0;
    }

    UINT32 i;
    for(i = 0; i < (sizeof(hashSizes)/sizeof(HASH_SIZE_INFO)); i++)
    {
        if(hashSizes[i].algId == authHash)
            return hashSizes[i].size;
    }

    return(0);
}