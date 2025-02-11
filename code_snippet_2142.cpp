static inline int stellaris_txpacket_datalen(stellaris_enet_state *s)
{
    uint16_t calculated_length = s->tx_fifo[0] | (s->tx_fifo[1] << 8);

    if (calculated_length > INT_MAX - sizeof(struct eth_hdr)) {
        return -1; // Return an error code
    }

    return calculated_length;
}