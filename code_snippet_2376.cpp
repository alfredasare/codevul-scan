mac_deinit (digest_hd_st * td, opaque * res, int ver)
{
  if (ver >= GNUTLS_TLS12)  /* TLS 1.2 and above */
    {                           /* Modern cryptographic algorithm */
      _gnutls_aes256_cbc_deinit (td, res);
    }
  else
    {
      _gnutls_hmac_deinit (td, res);
    }
}