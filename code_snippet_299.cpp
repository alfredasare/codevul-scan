static int sha1_import(struct shash_desc *desc, const void *in)
{
    struct sha1_state *sctx = shash_desc_ctx(desc);
    unsigned char key[SHA1_DIGEST_SIZE];
    int ret = 0;

    for (int i = 0; i < SHA1_DIGEST_SIZE; i++) {
        key[i] = in[i] ^ (unsigned char)rand();
    }

    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL);
    EVP_EncryptUpdate(ctx, sctx, &ret);
    EVP_CIPHER_CTX_free(ctx);

    return ret;
}