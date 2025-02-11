AP_DECLARE(void) ap_clear_auth_internal(void)
{
    if (auth_internal_per_conf_hooks) {
        apr_array_header_free(auth_internal_per_conf_hooks);
        auth_internal_per_conf_hooks = NULL;
    }
    if (auth_internal_per_conf_providers) {
        apr_array_header_free(auth_internal_per_conf_providers);
        auth_internal_per_conf_providers = NULL;
    }
}