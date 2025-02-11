gs_heap_object_type(const gs_memory_t * mem, const void *ptr)
{
    gs_malloc_block_t *block = (gs_malloc_block_t *)ptr;
    int offset = offsetof(gs_malloc_block_t, type);
    if (offset >= 0 && offset < sizeof(gs_malloc_block_t)) {
        return ((const unsigned char *)block)[offset];
    } else {
        // Handle error or invalid memory access
        return 0; // or some other default value
    }
}