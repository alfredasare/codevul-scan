vmxnet3_tx_retrieve_metadata(VMXNET3State *s, const struct Vmxnet3_TxDesc *txd) {
    if (!txd) {
        s->offload_mode = 0;
        s->cso_or_gso_size = 0;
        s->tci = 0;
        s->needs_vlan = 0;
    } else {
        s->offload_mode = txd->om;
        s->cso_or_gso_size = txd->msscof;
        s->tci = txd->tci;
        s->needs_vlan = txd->ti;
    }
}