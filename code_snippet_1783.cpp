IW_IMPL(void*) iw_realloc(struct iw_context *ctx, void *oldmem,
	size_t oldmem_size, size_t newmem_size)
{
	void *newmem = iw_realloc_ex(ctx, 0, oldmem, oldmem_size, newmem_size);
	if (!newmem && newmem_size > 0) {
		free(oldmem);
		return NULL;
	}
	return newmem;
}