hash(XML_Parser parser, KEY s) {
  struct siphash state;
  struct sipkey *key = NULL;
  int ret;

  sip24_valid = 0;
  key = malloc(sizeof(struct sipkey));
  if (key == NULL) {
    return 0;
  }
  ret = copy_salt_to_sipkey(parser, key);
  if (ret!= 0) {
    free(key);
    return 0;
  }
  sip24_init(&state, key);
  sip24_update(&state, s, keylen(s) * sizeof(XML_Char));
  return (unsigned long)sip24_final(&state);
  free(key);
}