void EC_GROUP_free(EC_GROUP *group)
{
    if (!group)
        return;

    if (group->meth && group->meth->group_finish!= 0)
        group->meth->group_finish(group);

    if (group->mont_data)
        BN_MONT_CTX_free(group->mont_data);

    if (group->generator)
        EC_POINT_free(group->generator);

    if (group->order)
        BN_free(group->order);

    if (group->cofactor)
        BN_free(group->cofactor);

    if (group->seed)
        OPENSSL_free(group->seed);

    OPENSSL_free(group);
}