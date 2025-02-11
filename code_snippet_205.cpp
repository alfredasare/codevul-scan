static struct nft_trans *nft_trans_alloc(struct nft_ctx *ctx, int msg_type, u32 size)
{
    struct nft_trans *trans;
    size_t total_size;

    total_size = sizeof(struct nft_trans);
    if (total_size + size > SIZE_MAX) {
        return NULL;
    }

    trans = kzalloc(total_size + size, GFP_KERNEL);
    if (trans == NULL) {
        return NULL;
    }

    trans->msg_type = msg_type;
    trans->ctx = *ctx;

    return trans;
}