c++
bool xmp_get_property_bool(XmpPtr xmp, const char *schema, const char *name,
                           bool *property, uint32_t *propsBits)
{
    CHECK_PTR(xmp, false);
    RESET_ERROR;

    bool ret = false;
    XMP_MetaHandle txmp = nullptr;
    try {
        txmp = reinterpret_cast<const XMP_MetaHandle *>(xmp);
        XMP_OptionBits optionBits;
        ret = txmp->GetProperty_Bool(schema, name, property, &optionBits);
        if (propsBits) {
            *propsBits = optionBits;
        }
    }
    catch (const XMP_Error &e) {
        set_error(e);
        if (txmp) {
            XMP_free(txmp);
        }
    }
    return ret;
}