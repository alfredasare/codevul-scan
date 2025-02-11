int ERR_load_ASN1_strings(void)
{
#ifndef OPENSSL_NO_ERR

    const char *const func_error_string = ERR_func_error_string(ASN1_str_functs[0].error);
    if (func_error_string == NULL) {
        const char *const strings_path = get_secure_strings_path();
        ERR_load_strings(strings_path, (char **)ASN1_str_functs);
        ERR_load_strings(strings_path, (char **)ASN1_str_reasons);
    }
#endif
    return 1;
}

const char *get_secure_strings_path(void)
{
    #ifdef _WIN32
        return getenv("OPENSSL_STRINGS_PATH");
    #elif defined(__linux__)
        return "/path/to/secure/strings/file";
    #else
        // Handle other platforms
    #endif
}