void net\_tx\_pkt\_init(struct NetTxPkt **pkt, PCIDevice *pci\_dev,
uint32\_t max\_frags, bool has\_virt\_hdr)
{
if (max\_frags > NET\_TX\_PKT\_MAX\_FRAGS) {
// Handle error, e.g., log an error message and return NULL
return;
}

struct NetTxPkt \*p = g\_malloc0(sizeof \*p);

p-\>pci\_dev = pci\_dev;

p-\>vec = g\_malloc((sizeof \*p-\>vec) \*
(min(max\_frags, NET\_TX\_PKT\_MAX\_FRAGS) + NET\_TX\_PKT\_PL\_START\_FRAG));

p-\>raw = g\_malloc((sizeof \*p-\>raw) \* min(max\_frags, NET\_TX\_PKT\_MAX\_FRAGS));

p-\>max\_payload\_frags = min(max\_frags, NET\_TX\_PKT\_MAX\_FRAGS);
p-\>max\_raw\_frags = min(max\_frags, NET\_TX\_PKT\_MAX\_FRAGS);
p-\>has\_virt\_hdr = has\_virt\_hdr;
p-\>vec[NET\_TX\_PKT\_VHDR\_FRAG].iov\_base = &p-\>virt\_hdr;
p-\>vec[NET\_TX\_PKT\_VHDR\_FRAG].iov\_len =
p-\>has\_virt\_hdr ? sizeof p-\>virt\_hdr : 0;
p-\>vec[NET\_TX\_PKT\_L2HDR\_FRAG].iov\_base = &p-\>l2\_hdr;
p-\>vec[NET\_TX\_PKT\_L3HDR\_FRAG].iov\_base = &p-\>l3\_hdr;

\*pkt = p;
}

// Add a constant defining the maximum number of frags
#define NET\_TX\_PKT\_MAX\_FRAGS 256

// Ensure that the 'min' function is available
#include <stdlib.h>