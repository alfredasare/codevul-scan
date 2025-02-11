base::string16 SaveCardBubbleControllerImpl::GetWindowTitle() const {
return base::string16(l10n_util::GetStringUTF16(
is\_uploading\_ ? IDS\_AUTOFILL\_SAVE\_CARD\_PROMPT\_TITLE\_TO\_CLOUD
: IDS\_AUTOFILL\_SAVE\_CARD\_PROMPT\_TITLE\_LOCAL));
}