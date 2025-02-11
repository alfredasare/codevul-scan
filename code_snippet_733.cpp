virtual void OnJSONParseFailed(const std::string& error\_message) {
> if(!error\_message.empty()) {
   CHECK(BrowserThread::CurrentlyOn(BrowserThread::IO));
   manifest\_parse\_complete\_ = true;
   error\_ = error\_message;
   parse\_error\_ = BeginInstallWithManifestFunction::MANIFEST\_ERROR;
   ReportResultsIfComplete();
}
}