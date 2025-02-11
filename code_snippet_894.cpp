c++
bool UnacceleratedStaticBitmapImage::IsPremultiplied() const {
    if (paint_image_ && paint_image_->GetSkImage()) {
        return paint_image_->GetSkImage()->alphaType() == SkAlphaType::kPremul_SkAlphaType;
    }
    return false;
}