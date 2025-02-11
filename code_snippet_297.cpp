static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
		       struct scatterlist *src, unsigned int nbytes)
{
    struct twofish_xts_ctx *ctx = crypto_blcipher_ctx(desc->tfm);
    unsigned int dst_len = sg_nents_to_bytes(dst);
    unsigned int src_len = sg_nents_to_bytes(src);

    if (nbytes > dst_len || nbytes > src_len) {
        return -EINVAL;
    }

    return glue_xts_crypt_128bit(&twofish_enc_xts, desc, dst, src, nbytes,
				     XTS_TWEAK_CAST(twofish_enc_blk),
				     &ctx->tweak_ctx, &ctx->crypt_ctx);
}