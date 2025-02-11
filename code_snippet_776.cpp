bool UnacceleratedStaticBitmapImage::IsPremultiplied() const {
  if (!paint_image_) {
    return false;
  }
  return paint_image_->GetSkImage()->alphaType() >= SkAlphaType::kPremul_SkAlphaType &&
         paint_image_->GetSkImage()->alphaType() <= SkAlphaType::kPremul_SkAlphaType;
}