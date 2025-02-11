ossl\_cipher\_get\_auth\_tag(int argc, VALUE *argv, VALUE self)
{
    VALUE vtag\_len, ret;
    EVP\_CIPHER\_CTX \*ctx;
    size\_t tag\_len = 16;

    rb\_scan\_args(argc, argv, "01", &vtag\_len);
    if (NIL\_P(vtag\_len))
	vtag\_len = rb\_attr\_get(self, id\_auth\_tag\_len);
    if (!NIL\_P(vtag\_len))
	tag\_len = NUM2SIZET(vtag\_len);

    GetCipher(self, ctx);

    if (!(EVP\_CIPHER\_CTX\_flags(ctx) & EVP\_CIPH\_FLAG\_AEAD\_CIPHER))
	ossl\_raise(eCipherError, "authentication tag not supported by this cipher");

    ret = rb\_str\_new(NULL, tag\_len);
    if (!EVP\_CIPHER\_CTX\_ctrl(ctx, EVP\_CTRL\_AEAD\_GET\_TAG, tag\_len, RSTRING\_PTR(ret)))
	ossl\_raise(eCipherError, "retrieving the authentication tag failed");

    return ret;
}