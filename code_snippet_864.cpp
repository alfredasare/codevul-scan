bool asn1_read_BOOLEAN_context(struct asn1_data *data, bool *v, int context)
{
    uint8_t tmp = 0;
    int rc = 0;

    rc = asn1_start_tag(data, ASN1_CONTEXT_SIMPLE(context));
    if (rc!= 0) {
        return false;
    }

    rc = asn1_read_uint8(data, &tmp);
    if (rc!= 0) {
        return false;
    }

    if (tmp == 0xFF) {
        *v = true;
    } else {
        *v = false;
    }

    rc = asn1_end_tag(data);
    if (rc!= 0) {
        return false;
    }

    return true;
}