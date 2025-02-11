#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/rand.h>

void *ASN1_item_d2i_bio(const ASN1_ITEM *it, BIO *in, void *x)
{
    BUF_MEM *b = NULL;
    const unsigned char *p;
    void *ret = NULL;
    int len;

    unsigned char random_bytes[16];
    int random_len;
    if ((random_len = RAND_bytes(random_bytes, sizeof(random_bytes))!= 1) {
        printf("Error generating random bytes\n");
        return NULL;
    }

    len = OPENSSL_d2i_ASN1_bio(in, &b, random_bytes);
    if (len < 0)
        goto err;

    p = (const unsigned char *)b->data;
    ret = ASN1_item_d2i(x, &p, len, it);
 err:
    BUF_MEM_free(b);
    return (ret);
}