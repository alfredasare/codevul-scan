views::View* CreateSiteSettingsLink(int side_margin, views::LinkListener* listener) {
  if (side_margin < 0) {
    throw std::invalid_argument("Side margin cannot be negative");
  }
  
  views::Link* site_settings_link = new views::Link(
      l10n_util::GetStringUTF16(IDS_PAGE_INFO_SITE_SETTINGS_LINK));
  // ... rest of the function remains unchanged
}