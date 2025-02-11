void H264SwDecRelease(H264SwDecInst decInst)
{
    decContainer_t *pDecCont;

    DEC_API_TRC("H264SwDecRelease#");

    if (decInst == NULL) {
        DEC_API_TRC("H264SwDecRelease# ERROR: decInst == NULL");
        return;
    }

    pDecCont = (decContainer_t*)decInst;

    #ifdef H264DEC_TRACE
    char str[256]; // Define a fixed-size buffer
    snprintf(str, sizeof(str), "H264SwDecRelease# decInst %p", decInst);
    DEC_API_TRC(str);
    #endif

    h264bsdShutdown(&pDecCont->storage);

    H264SwDecFree(pDecCont);
}