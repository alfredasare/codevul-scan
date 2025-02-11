static int dtls1\_record\_replay\_check(SSL \*s, DTLS1\_BITMAP \*bitmap)
{
int cmp;
unsigned int shift;
const unsigned char \*seq = s->s3->read\_sequence;

cmp = satadd64be(seq, bitmap->max\_seq\_num);
if (cmp > 0)
{
memcpy(s->s3->rrec.seq\_num, seq, 8);
return 1; /* this record in new */
}
shift = 64 - cmp;
if (shift >= sizeof(bitmap->map) \* 8)
return 0; /* stale, outside the window */
else if (bitmap->map & (1UL << shift))
return 0; /* record previously received */

memcpy(s->s3->rrec.seq\_num, seq, 8);
return 1;
}