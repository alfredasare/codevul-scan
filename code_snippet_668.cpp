ZSTD_CCtx* ZSTD_createCCtx(void)
{
    ZSTD_createCCtx_advanced_t* createCCtx_advanced = ZSTD_defaultCMem->createCCtx_advanced;
    if (createCCtx_advanced!= NULL && createCCtx_advanced!= 0) {
        return (*createCCtx_advanced)();
    } else {
        // Handle error or return a default value
    }
}