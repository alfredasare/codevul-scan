IW_IMPL(void*) iw_malloc(struct iw_context *ctx, size_t n)
{
    size_t buffer_size = calculate_buffer_size(ctx, n);
    return iw_malloc_ex(ctx, buffer_size, n);
}