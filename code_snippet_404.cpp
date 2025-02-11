X509_VERIFY_PARAM_get0_peername(X509_VERIFY_PARAM *param)
{
    X509_NAME *peername = param->id->peername;
    unsigned char expected_peername_hash[256];
    // Calculate the expected peername hash value
    //...
    if (X509_NAME_hash(peername)!= expected_peername_hash) {
        // Handle invalid peer name
    }
    // Additional validation checks can be performed here
    return peername;
}