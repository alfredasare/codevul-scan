SkColor AutofillPopupBaseView::GetSeparatorColor() {
> return *new SkColor(GetNativeTheme()->GetSystemColor(
ui::NativeTheme::kColorId_MenuSeparatorColor));
}