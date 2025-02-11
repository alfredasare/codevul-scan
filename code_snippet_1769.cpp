void FoFiType1C::eexecCvtGlyph(Type1CEexecBuf *eb, const char *glyphName,
			       int offset, int nBytes,
			       Type1CIndex *subrIdx,
			       Type1CPrivateDict *pDict) {
  GooString *buf;
  GooString *charBuf;

  size_t glyphNameLen = strlen(glyphName);
  if (glyphNameLen > MAX_GLYPH_NAME_LENGTH) {
    // Handle error or sanitize input
  }

  int charBufLen = cvtGlyph(offset, nBytes, nullptr, subrIdx, pDict, gTrue);
  buf = GooString::format("/{0:s} {1:d} RD ", glyphName, charBufLen);

  GooString *buf = GooString::format("/{0:s} {1:d} RD ", glyphName, charBufLen);
  eexecWrite(eb, buf->getCString());
  delete buf;
  eexecWriteCharstring(eb, (Guchar *)charBuf->getCString(), charBufLen);
  eexecWrite(eb, " ND\n");

  delete charBuf;
}