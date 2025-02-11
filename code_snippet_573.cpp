cmsFloat64Number CMSEXPORT cmsIT8GetPropertyDbl(cmsHANDLE hIT8, const char* cProp)
{
    const char *v = (const char*)cmsIT8GetProperty(hIT8, cProp); // Cast to const char*

    if (v == NULL) return 0.0;

    return/cmsFloat64Number_from_string(v); // Use a safe conversion function
}