int BN_is_bit_set(const BIGNUM *a, size_t n)
{
	size_t i, j;

	bn_check_top(a);
	if (n >= a->top * BN_BITS2) return 0;
	i = n / BN_BITS2;
	j = n % BN_BITS2;
	return (int)(((a->d[i]) >> j) & ((BN_ULONG)1));
}