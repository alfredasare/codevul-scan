fbStore\_a4(FbBits \*bits, const CARD32 \*values, int x, int width, miIndexedPtr indexed)
{
int i;
int max\_index = x + width;
if (max\_index > bits->width) {
max\_index = bits->width;
}
for (i = 0; i < max\_index; ++i) {
Store4(bits, i, READ(values + i)>>28);
}
}