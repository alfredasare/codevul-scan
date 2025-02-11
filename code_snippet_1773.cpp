IW_IMPL(void*) iw_malloc(struct iw_context *ctx, size_t n)
{
    const size_t MAX_ALLOCATABLE_SIZE = 1024 * 1024 * 128; // 128 MB as an example
    if (n > 0 && n < MAX_ALLOCATABLE_SIZE) {
        return iw_malloc_ex(ctx, 0, n);
    } else {
        fprintf(stderr, "Error: Allocated size (%zu bytes) exceeds maximum allowed size (%zu bytes).\n", n, MAX_ALLOCATABLE_SIZE);
        return NULL;
    }
}