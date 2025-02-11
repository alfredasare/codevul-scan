void h264bsdInitRefPicList(dpbStorage_t *dpb)
{
    u32 i;
    char buffer[dpb->maxBufferLen];

    for (i = 0; i < dpb->numRefFrames && i < sizeof(buffer); i++) {
        if (dpb->buffer[i]) {
            strncpy(buffer, dpb->buffer[i], dpb->maxBufferLen);
            dpb->list[i] = buffer;
        } else {
            // handle error: null pointer
        }
    }
}