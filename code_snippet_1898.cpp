SkCodec::Result SkIcoCodec::onStartScanlineDecode(const SkImageInfo& dstInfo,
                                                 const SkCodec::Options& options) {
    int index = 0;
    SkCodec::Result result = kInvalidScale;
    int maxIndex = fEmbeddedCodecs->size() - 1; // Get the maximum possible index

    while (true) {
        index = this->chooseCodec(dstInfo.dimensions(), index);
        if (index < 0) {
            break;
        }

        if (index > maxIndex) { 
            SkCodecPrintf("Error: Index out of bounds.\n");
            return kInvalidScale;
        }

        SkCodec* embeddedCodec = fEmbeddedCodecs->operator[](index).get();
        result = embeddedCodec->startScanlineDecode(dstInfo, &options);
        if (kSuccess == result) {
            fCurrScanlineCodec = embeddedCodec;
            fCurrIncrementalCodec = nullptr;
            return result;
        }

        index++; 
    }

    return result;
}