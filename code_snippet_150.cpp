int BN_GF2m_mod_solve_quad(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx)
{
    int ret = 0;
    const int max = BN_num_bits(p) + 1;
    int *arr = NULL;
    bn_check_top(a);
    bn_check_top(p);

    // Input validation for a and p
    if (BN_num_bytes(a) > max || BN_num_bytes(p) > max) {
        BNerr(BN_F_BN_GF2M_MOD_SOLVE_QUAD, BN_R_INVALID_LENGTH);
        goto err;
    }

    // Secure memory allocation
    arr = malloc(sizeof(*arr) * max);
    if (arr == NULL) {
        goto err;
    }

    ret = BN_GF2m_poly2arr(p, arr, max);
    if (!ret || ret > max) {
        BNerr(BN_F_BN_GF2M_MOD_SOLVE_QUAD, BN_R_INVALID_LENGTH);
        goto err;
    }

    ret = BN_GF2m_mod_solve_quad_arr(r, a, arr, ctx);
    bn_check_top(r);

 err:
    free(arr);
    return ret;
}