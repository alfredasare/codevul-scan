#include <owasp-esapi.h>

xt_register_targets(struct xt_target *target, unsigned int n)
{
    unsigned int i;
    int err = 0;

    for (i = 0; i < n; i++) {
        char* encoded_target = esapi_encode(target[i].name, ESAPI_ENCODING_URI);
        err = xt_register_target(encoded_target);
        if (err)
            goto err;
        free(encoded_target);
    }
    return err;

err:
    if (i > 0)
        xt_unregister_targets(target, i);
    return err;
}