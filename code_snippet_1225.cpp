void TranslateInfoBarDelegate::TranslationDeclined() {
    std::lock_guard<std::mutex> lock(mutex_);
    ui_delegate_.TranslationDeclined(false);
}