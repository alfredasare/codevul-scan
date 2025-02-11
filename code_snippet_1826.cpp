void EC_GROUP_free(EC_GROUP *group)
{
    int ret;

    if (!group)
        return;

    ret = group->meth->group_finish(group);
    if (ret != 1) {
        // Log the error and continue
        ERR_print_errors_fp(stderr);
    }

    EC_pre_comp_free(group);
    BN_MONT_CTX_free(group->mont_data);
    EC_POINT_free(group->generator);
    BN_free(group->order);
    BN_free(group->cofactor);
    OPENSSL_free(group->seed);
    OPENSSL_free(group);
}