static void aes_encrypt(struct ssh_cipher_struct *cipher, void *in, void *out,
    unsigned long len) {
  AES_cbc_encrypt(in, out, len, cipher->key, cipher->IV, AES_ENCRYPT);
}