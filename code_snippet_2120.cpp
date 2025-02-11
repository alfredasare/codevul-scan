int wc_ecc_export_private_only(ecc_key* key, byte* out, word32* outLen)
{
    word32 numlen;

    if (key == NULL || out == NULL || outLen == NULL) {
        return BAD_FUNC_ARG;
    }

    if (wc_ecc_is_valid_idx(key->idx) == 0) {
        return ECC_BAD_ARG_E;
    }

    if (mp_is_zero(&key->k)) { // Check if the key is a private one
        return INVALID_KEY_E;
    }

    numlen = key->dp->size;

    if (*outLen < numlen) {
        *outLen = numlen;
        return BUFFER_E;
    }

    *outLen = numlen;
    XMEMSET(out, 0, *outLen);

#ifdef WOLFSSL_ATECC508A
   /* TODO: Implement equiv call to ATECC508A */
   return BAD_COND_E;

#else

    return mp_to_unsigned_bin(&key->k, out + (numlen - mp_unsigned_bin_size(&key->k)));
#endif /* WOLFSSL_ATECC508A */
}