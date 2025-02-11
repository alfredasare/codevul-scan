++
const std::set<std::string> allowedImageIds = {"IDR_AURA_UBER_TRAY_CAST_STATUS"};

CastTrayView::CastTrayView(SystemTrayItem* tray_item)
  : TrayItemView(tray_item), weak_ptr_factory_(this) {
  CreateImageView();

  std::string imageId = ui::ResourceBundle::GetSharedInstance()
                       .GetImageNamed(IDR_AURA_UBER_TRAY_CAST_STATUS)
                       .name();
  if (!allowedImageIds.count(imageId)) {
    // Handle invalid image ID
  } else {
    image_view()->SetImage(ui::ResourceBundle::GetSharedInstance()
                         .GetImageNamed(imageId)
                         .ToImageSkia());
  }
}