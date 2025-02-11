WebString GetFormSignatureAsWebString(const PasswordForm& password_form) {
 return WebString::FromUTF8(
 base::NumberToString(CalculateFormSignatureSecure(password_form.form_data)));
}