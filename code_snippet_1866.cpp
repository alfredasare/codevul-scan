SkIcoCodec::SkIcoCodec(int width, int height, const SkEncodedInfo& info,
                         SkTArray<std::unique_ptr<SkCodec>, true>* codecs,
                         sk_sp<SkColorSpace> colorSpace)
  : INHERITED(width, height, info, SkColorSpaceXform::ColorFormat(), nullptr, std::move(colorSpace))
, fEmbeddedCodecs(codecs? codecs->size() : 0)
, fCurrScanlineCodec(nullptr)
, fCurrIncrementalCodec(nullptr)
{
  if (codecs && codecs->size() > 0) {
    for (int i = 0; i < codecs->size(); i++) {
      if (i < fEmbeddedCodecs.size() && fEmbeddedCodecs[i]) {
        // Process the codec at index i
      }
    }
  }
}