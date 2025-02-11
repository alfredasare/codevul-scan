JBIG2SymbolDict::JBIG2SymbolDict(Guint segNumA, Guint sizeA):
JBIG2Segment(segNumA)
{
Guint i;

size = sizeA;
bitmaps = (JBIG2Bitmap **)g_new0(JBIG2Bitmap *, size + 1);
if (!bitmaps) {
error("Out of memory");
exit(1);
}
for (i = 0; i < size; ++i) {
bitmaps[i] = NULL;
}
genericRegionStats = NULL;
refinementRegionStats = NULL;
}