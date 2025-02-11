bool ConfirmInfoBarDelegate::Cancel() {
    if (!isValidDelegate()) {
        return false;
    }
    if (!validateDelegateProperties()) {
        return false;
    }
    return true;
}

bool ConfirmInfoBarDelegate::isValidDelegate() {
    return delegate!= nullptr;
}

bool ConfirmInfoBarDelegate::validateDelegateProperties() {
    return delegate->HasCorrectPropertiesAndMethods();
}