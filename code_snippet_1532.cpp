static void write_response(ESPState *s)
{
    trace_esp_write_response(s->status);
    s->ti_buf[0] = s->status;
    s->ti_buf[1] = 0;

    // Limit the input length to 16 characters
    const size_t max_input_length = 16;
    if (strnlen(s->ti_buf, max_input_length) >= max_input_length) {
        // Reject the input if it exceeds the maximum length
        return;
    }

    // Check for any command characters using memchr()
    const char command_characters[] = {"|&;()<>\n\r\0"};
    if (memchr(s->ti_buf, command_characters, max_input_length)) {
        // Reject the input if it contains any command characters
        return;
    }

    if (s->dma) {
        s->dma_memory_write(s->dma_opaque, s->ti_buf, 2);
        s->rregs[ESP_RSTAT] = STAT_TC | STAT_ST;
        s->rregs[ESP_RINTR] = INTR_BS | INTR_FC;
        s->rregs[ESP_RSEQ] = SEQ_CD;
    } else {
        s->ti_size = 2;
        s->ti_rptr = 0;
        s->ti_wptr = 0;
        s->rregs[ESP_RFLAGS] = 2;
    }
    esp_raise_irq(s);
}