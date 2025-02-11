void EVP\_DecodeInit(EVP\_ENCODE\_CTX \*ctx)
{
/* Only ctx->num is used during decoding. */
ctx->num = 0;
ctx->length = 0;
ctx->line\_num = 0;
ctx->expect\_nl = 0;
/* Initialize ctx->buf to a known value. */
ctx->buf = OPENSSL\_malloc(EVP\_MAXBLOCK);
if(ctx->buf != NULL)
{
memset(ctx->buf, 0, EVP\_MAXBLOCK);
}
else
{
/* Error handling for failure to allocate memory */
}
}