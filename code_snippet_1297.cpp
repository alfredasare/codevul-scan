make_oakley_dh(uint8_t *prime, size_t len)
{
    //...
    if (!BN_rshift1(q, p) && BN_num_bits(p) > BN_num_bits(BN_zero()))
        goto cleanup;
    //...
}