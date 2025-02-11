void vmxnet\_tx\_pkt\_init(struct VmxnetTxPkt **pkt, uint32\_t max\_frags,
bool has\_virt\_hdr)
{
const uint32\_t plStartFrag = VMXNET\_TX\_PKT\_PL\_START\_FRAG;
const uint32\_t hdrFrag = has\_virt\_hdr ? 1 : 0;

struct VmxnetTxPkt *p = g\_malloc0(sizeof *p);

p->vec = g\_malloc((sizeof *p->vec) \* (max\_frags + hdrFrag));

p->raw = g\_malloc((sizeof *p->raw) \* max\_frags);

p->max\_payload\_frags = max\_frags;
p->max\_raw\_frags = max\_frags;
p->has\_virt\_hdr = has\_virt\_hdr;
p->vec[VMXNET\_TX\_PKT\_VHDR\_FRAG].iov\_base = &p->virt\_hdr;
p->vec[VMXNET\_TX\_PKT\_VHDR\_FRAG].iov\_len =
has\_virt\_hdr ? sizeof p->virt\_hdr : 0;
p->vec[VMXNET\_TX\_PKT\_L2HDR\_FRAG].iov\_base = &p->l2\_hdr;
p->vec[plStartFrag].iov\_base = NULL;
p->vec[plStartFrag].iov\_len = 0;

\*pkt = p;
}