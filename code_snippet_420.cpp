SkColor AutofillPopupBaseView::GetSeparatorColor() {
  ui::NativeTheme* theme = GetNativeTheme();
  SkColor color = theme? theme->GetSystemColor(ui::NativeTheme::kColorId_MenuSeparatorColor) : kDefaultSeparatorColor;
  return color;
}