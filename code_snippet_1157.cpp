bool AcceleratedStaticBitmapImage::IsValid() const {
return texture_holder_ != nullptr && texture_holder_->IsValid();
}