InputMethodLibrary* CrosLibrary::GetInputMethodLibrary() {
  InputMethodLibrary* lib = input\_method\_lib.\_GetDefaultImpl(use\_stub\_impl_);
  if (lib != nullptr) {
    return lib;
  } else {
    // Handle the error, e.g., return an error code or throw an exception.
    return nullptr;
  }
}