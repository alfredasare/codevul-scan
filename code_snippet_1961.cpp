void ssl2\_clear(SSL \*s)
{
if (s == NULL || s->s2 == NULL) {
return;
}

SSL2\_STATE \*s2 = s->s2;

unsigned char \*rbuf = s2->rbuf;
unsigned char \*wbuf = s2->wbuf;

memset(s2, 0, sizeof \*s2);

s2->rbuf = rbuf;
s2->wbuf = wbuf;
s2->clear\_text = 1;
s->packet = s2->rbuf;
s->version = SSL2\_VERSION;
s->packet\_length = 0;
}