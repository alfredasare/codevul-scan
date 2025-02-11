static hm_fragment *dtls1_hm_fragment_new(unsigned long frag\_len, int reassembly)
{
hm\_fragment \*frag = NULL;
unsigned char \*buf = NULL;
unsigned char \*bitmask = NULL;

frag = OPENSSL\_malloc(sizeof(\*frag));
if (frag == NULL)
return NULL;

if (frag\_len && frag\_len <= MAX\_BUFFER\_SIZE) { // Added check for maximum buffer size
buf = OPENSSL\_malloc(frag\_len);
if (buf == NULL) {
OPENSSL\_free(frag);
return NULL;
}
}

/* zero length fragment gets zero frag->fragment */
frag->fragment = buf;

/* Initialize reassembly bitmask if necessary */
if (reassembly) {
bitmask = OPENSSL\_zalloc(RSMBLY\_BITMASK\_SIZE(frag\_len));
if (bitmask == NULL) {
OPENSSL\_free(buf);
OPENSSL\_free(frag);
return NULL;
}
}

frag->reassembly = bitmask;

return frag;
}