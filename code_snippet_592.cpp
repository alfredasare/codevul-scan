virtual void OnJSONParseFailed(const std::string& error_message) {
    if (!BrowserThread::IsValid(BrowserThread::IO)) {
        return;
    }

    std::set<std::string> allowed_directories = {"allowed_directory1", "allowed_directory2"};
    if (!allowed_directories.count(BrowserThread::CurrentlyOn(BrowserThread::IO))) {
        return;
    }

    std::string safe_path = std::filesystem::path(BrowserThread::CurrentlyOn(BrowserThread::IO)) / "filename.txt";
    manifest_parse_complete_ = true;
    error_ = error_message;
    parse_error_ = BeginInstallWithManifestFunction::MANIFEST_ERROR;
    ReportResultsIfComplete();
}