static UINT16 GetDigestSize( TPM_ALG_ID authHash )
{
    UINT32 i;
    const UINT32 hashSizesCount = sizeof(hashSizes) / sizeof(HASH_SIZE_INFO);
    for(i = 0; i < hashSizesCount; i++ )
    {
        if( hashSizes[i].algId == authHash )
            return hashSizes[i].size;
    }

    return( 0 );
}