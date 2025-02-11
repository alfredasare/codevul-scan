c++
base::string16 SaveCardBubbleControllerImpl::GetWindowTitle() const {
  const std::set<std::string> allowedTitles = {IDS_AUTOFILL_SAVE_CARD_PROMPT_TITLE_TO_CLOUD, IDS_AUTOFILL_SAVE_CARD_PROMPT_TITLE_LOCAL};
  const std::string input = is_uploading_? IDS_AUTOFILL_SAVE_CARD_PROMPT_TITLE_TO_CLOUD : IDS_AUTOFILL_SAVE_CARD_PROMPT_TITLE_LOCAL;
  
  // Validate input string
  if (!allowedTitles.count(input)) {
    LOG(ERROR) << "Invalid title ID: " << input;
    return "";
  }
  
  return l10n_util::GetStringUTF16(input);
}