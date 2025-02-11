ssize_t pdu_unmarshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...)
{
    ssize_t ret;
    va_list ap;

    if (strspn(fmt, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_%")!= strlen(fmt))
    {
        return -EINVAL;
    }

    va_start(ap, fmt);
    ret = pdu_unmarshal_safe(pdu, offset, fmt, ap);
    va_end(ap);

    return ret;
}

ssize_t pdu_unmarshal_safe(V9fsPDU *pdu, size_t offset, const char *fmt, va_list ap)
{
    // Implement your own parsing logic without relying on format strings
    //...
}