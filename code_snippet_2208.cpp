int ERR_load_ASN1_strings(void)
{
#ifndef OPENSSL_NO_ERR

    if (ERR_func_error_string(ASN1_str_functs[0].error) == NULL) {
        if (ERR_load_strings(0, ASN1_str_functs) !=