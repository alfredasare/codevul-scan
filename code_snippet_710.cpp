cmsFloat64Number CMSEXPORT cmsIT8GetPropertyDbl(cmsHANDLE hIT8, const char* cProp)
{
    const char *v = cmsIT8GetProperty(hIT8, cProp);

    if (v == NULL || strlen(cProp) >= MAX_PROPERTY_LENGTH) return 0.0; // Add length check

    return ParseFloatNumber(v);
}