int BN_is_bit_set(const BIGNUM *a, int n)
{
    if (n < 0) {
        return 0;
    }

    bn_check_top(a);
    int i = n / BN_BITS2;
    int j = n % BN_BITS2;
    if (a->top <= i) {
        return 0;
    }
    return (int)(((a->d[i]) >> j) & ((BN_ULONG)1));
}