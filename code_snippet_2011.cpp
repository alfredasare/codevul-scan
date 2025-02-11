int wc_ecc_export_private_only(ecc_key* key, byte* out, word32* outLen)
{
    word32 numlen;

    if (key == NULL || out == NULL || outLen == NULL) {
        return -1; // Generic error code
    }

    if (wc_ecc_is_valid_idx(key->idx) == 0) {
        return -2; // Standardized error code
    }
    numlen = key->dp->size;

    if (*outLen < numlen) {
        *outLen = numlen;
        return -3; // Generic error code
    }
    *outLen = numlen;
    XMEMSET(out, 0, *outLen);

#ifdef WOLFSSL_ATECC508A
   /* TODO: Implement equiv call to ATECC508A */
   return -4; // Generic error code

#else

    return mp_to_unsigned_bin(&key->k, out + (numlen - mp_unsigned_bin_size(&key->k)));
#endif /* WOLFSSL_ATECC508A */
}