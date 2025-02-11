vmxnet3\_tx\_retrieve\_metadata(VMXNET3State \*s,
const struct Vmxnet3\_TxDesc \*txd)
{
if (sizeof(s->offload\_mode) >= txd->om &&
sizeof(s->cso\_or\_gso\_size) >= txd->msscof &&
sizeof(s->tci) >= txd->tci &&
sizeof(s->needs\_vlan) >= txd->ti) {
s->offload\_mode = txd->om;
s->cso\_or\_gso\_size = txd->msscof;
s->tci = txd->tci;
s->needs\_vlan = txd->ti;
} else {
// Handle error
}
}