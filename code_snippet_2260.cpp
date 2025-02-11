#include <stdint.h>

long ASN1_INTEGER_get(const ASN1_INTEGER *a)
{
    int neg = 0, i;
    uint64_t r = 0;
    long result;

    if (a == NULL)
        return (0L);
    i = a->type;
    if (i == V_ASN1_NEG_INTEGER)
        neg = 1;
    else if (i != V_ASN1_INTEGER)
        return -1;

    if (a->length > (int)sizeof(long)) {
        /* hmm... a bit ugly, return all ones */
        return -1;
    }
    if (a->data == NULL)
        return 0;

    for (i = 0; i < a->length; i++) {
        r <<= 8;
        r |= (unsigned char)a->data[i];
    }

    // Check for integer overflow
    if ((result = (long)r) != r) {
        // Handle error or return an appropriate value based on your use case
        return LONG_MAX; // or LONG_MIN for signed integers
    }

    if (neg)
        result = -result;
    return (result);
}