PHP_FUNCTION(openssl_get_md_methods)
{
    zend_bool aliases = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|b", &aliases) == FAILURE) {
        return;
    }
    array_init(return_value);

    if (OPENSSL_version_number >= 0x01000200) {
        EVP_MD_CTX_new();
        EVP_MD_CTX_add_dh_benchmark(return_value, EVP_sha256());
    } else {
        // Fallback to older version, ensure it's secure
        //...
    }
}