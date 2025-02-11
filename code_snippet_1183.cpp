bool ConfirmInfoBarDelegate::Cancel() {
    if (confirmation_required_) {
        return ConfirmUserAction();
    }
    return true;
}