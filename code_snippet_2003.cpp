SkIcoCodec::SkIcoCodec(int width, int height, const SkEncodedInfo& info,
SkTArray<std::unique_ptr<SkCodec>, true>* codecs,
sk\_sp<SkColorSpace> colorSpace)
: INHERITED(std::max(1, std::min(width, MAX\_WIDTH)), std::max(1, std::min(height, MAX\_HEIGHT)), info, SkColorSpaceXform::ColorFormat(), nullptr,
std::move(colorSpace))
, fEmbeddedCodecs(codecs)
, fCurrScanlineCodec(nullptr)
, fCurrIncrementalCodec(nullptr)
{}