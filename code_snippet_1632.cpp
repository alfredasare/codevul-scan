void AppLayerProtoDetectUnittestCtxRestore(void)
{
    SCEnter();
    alpd_ctx = alpd_ctx_ut;
    size_t ut_size = sizeof(alpd_ctx_ut);
    memset(&alpd_ctx_ut, 0, ut_size);
    SCReturn;
}