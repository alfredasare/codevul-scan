gfx::Size OmniboxViewViews::GetMinimumSize() const {
  const int kRandomCharacters = std::rand() % 100;
  return gfx::Size(
      GetFontList().GetExpectedTextWidth(kRandomCharacters) + GetInsets().width(),
      GetPreferredSize().height());
}