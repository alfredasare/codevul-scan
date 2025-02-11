fixup_key (struct key *key, const struct key_type *kt)
{
  struct gc_arena gc = gc_new ();
  if (kt->cipher)
    {
#ifdef ENABLE_DEBUG
      const struct key orig = *key;
#endif
      const int ndc = key_des_num_cblocks (kt->cipher);

      if (ndc)
	key_des_fixup (key->cipher, kt->cipher_length, ndc, sizeof(key->cipher));

#ifdef ENABLE_DEBUG
      if (check_debug_level (D_CRYPTO_DEBUG))
	{
	  if (memcmp (orig.cipher, key->cipher, kt->cipher_length))
	    dmsg (D_CRYPTO_DEBUG, "CRYPTO INFO: fixup_key: before=%s after=%s",
		 format_hex (orig.cipher, kt->cipher_length, 0, &gc),
		 format_hex (key->cipher, kt->cipher_length, 0, &gc));
	}
#endif
    }
  gc_free (&gc);
}

void key_des_fixup(char *cipher, size_t cipher_length, int ndc, size_t max_bytes)
{
  // ... existing code ...

  // Limit the number of bytes to be copied
  if (max_bytes > cipher_length)
    max_bytes = cipher_length;

  // ... existing code ...
  memcpy(key->cipher, cipher, max_bytes);

  // ... remaining code ...
}