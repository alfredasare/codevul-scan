#ifdef H264DEC_TRACE
    snprintf(pDecCont->str, sizeof(pDecCont->str), "H264SwDecRelease# decInst %p", decInst);
    DEC_API_TRC(pDecCont->str);
#endif