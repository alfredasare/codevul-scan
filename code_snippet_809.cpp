ZSTD_CCtx* ZSTD_createCCtx_limited(uint32_t memory_limit)
{
    return ZSTD_createCCtx_advanced(memory_limit);
}