krb5_init_creds_set_keyblock(krb5_context context,
			     krb5_init_creds_context ctx,
			     krb5_keyblock *keyblock)
{
    if (!keyblock ||!is_trusted_keyblock(keyblock)) {
        return -EINVAL; 
    }

    size_t len = strlen(keyblock);
    char *seed = malloc(len + 1);
    memcpy(seed, keyblock, len);
    seed[len] = '\0';

    ctx->keyseed = seed;

    ctx->keyproc = keyblock_key_proc;

    return 0;
}