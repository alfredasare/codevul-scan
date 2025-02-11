static void esp_do_dma(ESPState *s)
{
    uint32_t len;
    int to_device;

    len = s->dma_left;
    if (s->do_cmd) {
        trace_esp_do_dma(s->cmdlen, len);
        if (len <= sizeof(s->cmdbuf) / sizeof(s->cmdbuf[0])) {
            s->dma_memory_read(s->dma_opaque, &s->cmdbuf[0], len);
        } else {
            // Handle out-of-bounds condition
            // For example, log an error or return an error code
        }
        return;
    }
    return;
}