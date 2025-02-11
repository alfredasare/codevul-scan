int i2d\_PKCS7\_fp\_secure(FILE *fp, PKCS7 *p7)
{
EVP\_CIPHER\_CTX \*ctx = NULL;
int len = 0;
unsigned char *enc\_data = NULL;

ctx = EVP\_CIPHER\_CTX\_new();
EVP\_EncryptInit\_ex(ctx, EVP\_aes\_256\_cbc(), NULL, NULL, NULL);
EVP\_EncryptUpdate(ctx, NULL, &len, p7->contents, p7->datalen);
enc\_data = (unsigned char \*)OPENSSL\_malloc(len);
EVP\_EncryptUpdate(ctx, enc\_data, &len, p7->contents, p7->datalen);
EVP\_EncryptFinal\_ex(ctx, enc\_data + len, &len);

fwrite(enc\_data, len, 1, fp);
OPENSSL\_free(enc\_data);
EVP\_CIPHER\_CTX\_free(ctx);

return len;
}