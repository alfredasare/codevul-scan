static uint8_t* avrc_get_data_ptr(BT_HDR* p_pkt) {
    if (p_pkt->offset >= p_pkt->len || (p_pkt->offset + sizeof(uint16_t)) > p_pkt->len) {
        return NULL;
    }

    return (uint8_t*)(p_pkt + 1) + p_pkt->offset;
}