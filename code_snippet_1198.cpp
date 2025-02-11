struct condition *compiler_create_condition(struct filter_op *fop)
{
    struct condition *cnd = SAFE_CALLOC(1, sizeof(struct condition));
    if (cnd == NULL) {
        return NULL;
    }
    memcpy(&cnd->fop, fop, sizeof(struct filter_op));
    return cnd;
}