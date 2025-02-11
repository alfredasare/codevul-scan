InputMethodLibrary* InputMethodLibrary::GetImpl(bool stub) {
  if (stub) {
    return new InputMethodLibraryStubImpl();
  } else {
    InputMethodLibraryImpl* impl = new InputMethodLibraryImpl();
    try {
      if (!impl->Init()) {
        LOG(ERROR) << "Failed to initialize InputMethodLibraryImpl";
        delete impl;
        return nullptr;
      }
    } catch (...) {
      LOG(ERROR) << "Caught exception while initializing InputMethodLibraryImpl";
      delete impl;
      throw;
    }
    delete impl; // Add this line to release memory
    return impl;
  }
}