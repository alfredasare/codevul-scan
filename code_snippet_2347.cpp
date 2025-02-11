chunk_grow(chunk_t *chunk, size_t sz)
{
    off_t offset;
    size_t memlen_orig = chunk->memlen;
    tor_assert(sz > chunk->memlen);

    // Allocate a new chunk with the maximum of requested size or double the current size
    size_t new_size = (sz > (chunk->memlen *