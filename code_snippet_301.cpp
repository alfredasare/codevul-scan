static int sha1_import(struct shash_desc *desc, const void *in)
{
	struct sha1_state *sctx = shash_desc_ctx(desc);

	if (sizeof(*sctx) < memcpy(sctx, in, sizeof(*sctx))) {
		return -EINVAL;
	}

	return 0;
}