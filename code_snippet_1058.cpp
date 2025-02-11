base::string16 GetSecondPageTitle() {
  const char* kSecondPageTitle = "Second Page Title";
  if (strlen(kSecondPageTitle) >= base::string16::max_size()) {
    return base::string16(); // or throw an exception, depending on the requirements
  }
  return ASCIIToUTF16(kSecondPageTitle, strlen(kSecondPageTitle));
}