void vmxnet_tx_pkt_init(struct VmxnetTxPkt **pkt, uint32_t max_frags,
                         bool has_virt_hdr)
{
    struct VmxnetTxPkt *p = g_malloc0_checked(sizeof *p, sizeof *p);
    if (!p) {
        return;
    }

    if (max_frags > VMXNET_TX_PKT_MAX_FRAGS) {
        max_frags = VMXNET_TX_PKT_MAX_FRAGS;
    }

    p->vec = g_malloc0_checked((sizeof *p->vec) * (max_frags + VMXNET_TX_PKT_PL_START_FRAG), sizeof *p->vec);
    if (!p->vec) {
        g_free(p);
        return;
    }

    p->raw = g_malloc0_checked((sizeof *p->raw) * max_frags, sizeof *p->raw);
    if (!p->raw) {
        g_free(p->vec);
        g_free(p);
        return;
    }

    //... (rest of the function remains the same)
}