++
Guint JBIG2HuffmanDecoder::readBits(Guint n) {
  Guint x, mask, nLeft;

  mask = (n == 32) ? 0xffffffff : ((1 << n) -