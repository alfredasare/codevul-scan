static uint8_t* avrc_get_data_ptr(BT_HDR* p_pkt) {
    size_t packet_size = sizeof(*p_pkt); 
    if (p_pkt->offset > packet_size) {
        printf("Invalid offset: %u\n");
        return NULL;
    }
    return (uint8_t*)(p_pkt + 1) + p_pkt->offset;
}