DEFINE_RUN_ONCE_STATIC(ossl_init_engine_afalg)
{
#   ifdef OPENSSL_INIT_DEBUG
    fprintf(stderr, "OPENSSL_INIT: ossl_init_engine_afalg: "
                    "engine_load_afalg_int()\n");
#   endif
    if (engine_load_afalg_int()!= 1) {
        /* Handle error */
        fprintf(stderr, "Error loading AFALG engine.\n");
        return 0; /* or some other appropriate error value */
    }
    return 1;
}