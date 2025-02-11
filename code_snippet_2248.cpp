int i2c_ASN1_INTEGER(ASN1_INTEGER *a, unsigned char **pp)
{
    int pad = 0, ret = 0, i = 0, neg = 0;
    unsigned char *p = NULL, *n = NULL, pb = 0;

    if (a == NULL || a->length <= 0)
        return (0);

    if (a->length > MAX_ALLOWED_LENGTH)
        return (0);

    neg = a->type & V_ASN1_NEG;

    if (a->length == 0)
        ret = 1;
    else {
        ret = a->length;
        i = a->data[0];

        if (!neg && (i > 127)) {
            pad = 1;
            pb = 0;
            //... (rest of the code remains the same)
        } else if (i == 128) {
            //... (rest of the code remains the same)
        }
    }

    ret += pad;
    return (ret);
}