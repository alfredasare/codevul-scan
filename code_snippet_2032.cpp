static inline int stellaris_txpacket_datalen(stellaris_enet_state *s)
{
    if (s->tx_fifo[0] > 0xFF || s->tx_fifo[1] > 0xFF) {
        // Handle invalid values
    }
    return (s->tx_fifo[0] & 0xFF) + ((s->tx_fifo[1] & 0xFF) << 8);
}