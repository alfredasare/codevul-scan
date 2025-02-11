WebRunnerBrowserContext::WebRunnerBrowserContext(base::FilePath data_dir_path)
>: data\_dir\_path_(std::move(data\_dir\_path)),
net\_log_(CreateNetLog()),
resource\_context\_(new ResourceContext()) {
if (!data\_dir\_path_.IsAbsolute()) {
LOG(ERROR) << "Data directory path is not absolute!";
return;
}

if (!data\_dir\_path_.Resolve(base::ThreadUtils::GetFileThreadPool())
.IsValid()) {
LOG(ERROR) << "Failed to resolve data directory path!";
return;
}

BrowserContext::Initialize(this, GetPath());
}