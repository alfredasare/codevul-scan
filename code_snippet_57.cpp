fixup_key (struct key *key, const struct key_type *kt)
{
  struct gc_arena gc = gc_new ();
  if (kt->cipher)
    {
      const int ndc = key_des_num_cblocks (kt->cipher);

      if (ndc)
        key_des_fixup (key->cipher, kt->cipher_length, ndc);

      gc_free (&gc);
    }
}