TfLiteRegistration* Register_DEPTHWISE_CONVOLUTION_NEON_OPT_UINT8() {
  static TfLiteRegistration r = {
      depthwise_conv::Init, depthwise_conv::Free, depthwise_conv::Prepare,
      depthwise_conv::EvalImpl<depthwise_conv::kNeonOptimized, kTfLiteUInt8>};
  return &r;
}