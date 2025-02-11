void net_tx_pkt_init(struct NetTxPkt **pkt, PCIDevice *pci_dev, uint32_t max_frags, bool has_virt_hdr)
{
    struct NetTxPkt *p = NULL;
    GError *error = NULL;

    p = g_malloc0(sizeof *p);
    if (p == NULL) {
        error = g_error_new(G_ERROR, "Failed to allocate memory");
        g_error_free(error);
        return;
    }

    p->pci_dev = pci_dev;

    p->vec = g_malloc((sizeof *p->vec) * (max_frags + NET_TX_PKT_PL_START_FRAG));
    if (p->vec == NULL) {
        error = g_error_new(G_ERROR, "Failed to allocate memory");
        g_error_free(error);
        g_free(p);
        return;
    }

    p->raw = g_malloc((sizeof *p->raw) * max_frags);
    if (p->raw == NULL) {
        error = g_error_new(G_ERROR, "Failed to allocate memory");
        g_error_free(error);
        g_free(p->vec);
        g_free(p);
        return;
    }

    p->max_payload_frags = max_frags;
    p->max_raw_frags = max_frags;
    p->has_virt_hdr = has_virt_hdr;
    p->vec[NET_TX_PKT_VHDR_FRAG].iov_base = &p->virt_hdr;
    p->vec[NET_TX_PKT_VHDR_FRAG].iov_len = p->has_virt_hdr? sizeof p->virt_hdr : 0;
    p->vec[NET_TX_PKT_L2HDR_FRAG].iov_base = &p->l2_hdr;
    p->vec[NET_TX_PKT_L3HDR_FRAG].iov_base = &p->l3_hdr;

    *pkt = p;
}