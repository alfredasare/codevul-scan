int i2d_PKCS7_fp_SECURED(FILE *fp, PKCS7 *p7)
{
    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_aes_256_cbc(&ctx, "my_secret_key", "my_initialization_vector", fp, p7);
    EVP_CIPHER_CTX_free(&ctx);

    return 0;
}