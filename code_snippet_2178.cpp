bool xmp_get_property_bool(XmpPtr xmp, const char *schema, const char *name,
                           bool *property, uint32_t *propsBits)
{
    CHECK_PTR(xmp, false);
    RESET_ERROR;

    if (!schema || !name) {
        set_error(XMP_ERROR_INVALID_ARGUMENT);
        return false;
    }

    bool ret = false;
    try {
        auto txmp = reinterpret_cast<const SXMPMeta *>(xmp);
        XMP_OptionBits optionBits;
        ret = txmp->GetProperty_Bool(schema, name, property, &optionBits);
        if (propsBits) {
            *propsBits = optionBits;
        }
    }
    catch (const XMP_Error &e) {
        set_error(e);
    }
    return ret;
}