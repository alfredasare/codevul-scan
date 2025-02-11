JBIG2SymbolDict::JBIG2SymbolDict(Guint segNumA, Guint sizeA):
  JBIG2Segment(segNumA)
{
  Guint i;
  guint32 size = sizeA; 

  if (size > MAX_BITMAPS || segNumA > MAX_SEGMENTS) {
    throw std::invalid_argument("Invalid input values");
  }

  bitmaps = (JBIG2Bitmap **)g_malloc(size * sizeof(JBIG2Bitmap *));
  if (!bitmaps) {
    size = 0;
  } else {
    for (i = 0; i < size; ++i) {
      bitmaps[i] = NULL;
    }
  }
  genericRegionStats = NULL;
  refinementRegionStats = NULL;
}