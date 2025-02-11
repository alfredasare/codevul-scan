X509_VERIFY_PARAM_get0_peername(X509_VERIFY_PARAM *param)
{
    if (param == NULL || param->id == NULL) {
        /* Handle error condition appropriately, e.g., return an error code or log an error message */
        return NULL;
    }

    return param->id->peername;
}