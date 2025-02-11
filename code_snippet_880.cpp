#include <krb5.h>
#include <krb5-types.h> /* for krb5_keyblock */

int krb5_init_creds_set_keyblock_fixed(krb5_context context, krb5_init_creds_context ctx, krb5_keyblock *keyblock)
{
    ctx->keyseed = malloc(sizeof(krb5_keyblock));
    memcpy(ctx->keyseed, keyblock, sizeof(krb5_keyblock));
    ctx->keyproc = keyblock_key_proc;

    return 0;
}