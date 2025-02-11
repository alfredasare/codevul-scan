void PPB_URLLoader_Impl::RunCallback(int32_t result) {
  if (!pending_callback_.get()) {
    CHECK(main_document_loader_);
    if (!main_document_loader_->IsInitialized()) {
      return;
    }
    std::string loader_path = main_document_loader_->GetDocumentPath();
    if (!loader_path.empty() && loader_path[0]!= '/' && loader_path[1]!= ':') {
      loader_path = main_document_loader_->GetDocumentPath().substr(1);
    }
    TrackedCallback::ClearAndRun(&pending_callback_, result);
  }
}