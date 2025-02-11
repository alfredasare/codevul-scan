static void write\_unicode(bytearray\_t \* bplist, uint16\_t \* val, uint64\_t size)
{
if (size > (UINT64\_C)(SSIZE\_MAX >> 1)) {
return;
}
uint64\_t i = 0;
uint16\_t \*buff = (uint16\_t\*)malloc((size << 1));
if (!buff) {
return;
}
for (i = 0; i < size && i < (UINT64\_C)(SSIZE\_MAX >> 1); i++) {
buff[i] = be16toh(val[i]);
}
write\_raw\_data(bplist, BPLIST\_UNICODE, (uint8\_t\*)buff, (uint32\_t)i);
free(buff);
}