int EVP_CipherFinal_ex(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)
{
    if (ctx->encrypt) {
        if (*outl > INT_MAX) {
            ERR_error(ERR_INT_OVERFLOW, "Output length exceeds maximum integer value");
            return -1;
        }
        return EVP_EncryptFinal_ex(ctx, out, (unsigned int *)outl);
    } else {
        if (*outl < 0) {
            ERR_error(ERR_INT_UNDERFLOW, "Output length cannot be negative");
            return -1;
        }
        return EVP_DecryptFinal_ex(ctx, out, (unsigned int *)outl);
    }
}