bool extractResFilePathParts(const StringPiece16& path, StringPiece16* outPrefix, StringPiece16* outEntry, StringPiece16* outSuffix) {
    if (!stringStartsWith<char16_t>(path, u"res/")) {
        return false;
    }

    *outPrefix = StringPiece16(path.begin(), path.find(u"/", StringPiece16(u"res/").size()));
    auto iter = path.find(u'.', outPrefix->end());
    *outEntry = StringPiece16(outPrefix->end(), iter - outPrefix->end());
    *outSuffix = StringPiece16(iter, path.end() - iter);
    return true;
}