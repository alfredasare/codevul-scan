void FoFiType1C::getIndex(int pos, Type1CIndex *idx, GBool *ok) {
  idx->pos = pos;
  idx->len = getU16BE(pos, ok);
  if (idx->len == 0) {
    idx->offSize = 0;
    idx->startPos = idx->endPos = pos + 2;
  } else {
    idx->offSize = getU8(pos + 2, ok);
    if (idx->offSize < 1 || idx->offSize > 4) {
      *ok = gFalse;
    }
    int startPosCalc = pos + 3 + (idx->len + 1) * idx->offSize - 1;
    if (startPosCalc < 0 || startPosCalc >= len) {
      *ok = gFalse;
    }
    idx->startPos = std::min(std::max(startPosCalc, 0), len - 1);
    int endPosCalc = idx->startPos + getUVarBE(pos + 3 + idx->len * idx->offSize, idx->offSize, ok);
    if (endPosCalc < idx->startPos || endPosCalc > len) {
      *ok = gFalse;
    }
    idx->endPos = std::min(std::max(endPosCalc, 0), len - 1);
  }
}