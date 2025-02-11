static uint8_t *smbXcli\_iov\_concat(TALLOC\_CTX \*mem\_ctx,
const struct iovec \*iov,
int count)
{
ssize\_t buflen;
uint8\_t \*buf;

buflen = iov\_buflen(iov, count);
if (buflen == -1) {
return NULL;
}

if (buflen > 0) {
buf = talloc\_array(mem\_ctx, uint8\_t, buflen + 1);
if (buf == NULL) {
return NULL;
}

iov\_buf(iov, count, buf, buflen);
buf[buflen] = '\0';

return buf;
}

return NULL;
}