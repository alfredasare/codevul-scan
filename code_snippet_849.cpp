#define MAX_SIP_INPUT_SIZE (1024 * 1024) // Adjust the maximum size according to your needs

hash(XML_Parser parser, KEY s) {
  struct siphash state;
  struct sipkey key;
  (void)sip24_valid;
  copy_salt_to_sipkey(parser, &key);
  sip24_init(&state, &key);

  if (keylen(s) * sizeof(XML_Char) > MAX_SIP_INPUT_SIZE) {
    return 0;
  }

  sip24_update(&state, s, keylen(s) * sizeof(XML_Char));
  return (unsigned long)sip24_final(&state);
}