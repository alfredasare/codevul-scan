std::unique\_ptr<WebContents> WebContents::CreateWithSessionStorage(const WebContents::CreateParams& params, const SessionStorageNamespaceMap& session\_storage\_namespace\_map) {
std::unique\_ptr<WebContentsImpl> new\_contents(new WebContentsImpl(params.browser\_context));
RenderFrameHostImpl\* opener\_rfh = FindOpenerRFH(params);
FrameTreeNode\* opener = nullptr;
if (opener\_rfh)
opener = opener\_rfh->frame\_tree\_node();
new\_contents->SetOpenerForNewContents(opener, params.opener\_suppressed);

// Validate session\_storage\_namespace\_map
for (const auto& entry : session\_storage\_namespace\_map) {
if (!entry.second) {
// Handle invalid entry or log an error here
// For example:
// LOG(ERROR) << "Invalid session\_storage\_namespace\_map entry: "
// << "namespace\_name=" << entry.first
// << ", session\_storage\_namespace=nullptr";
return {};
}
if (entry.first.empty()) {
// Handle empty namespace name error here
return {};
}
}

for (const auto& entry : session\_storage\_namespace\_map) {
new\_contents->GetController().SetSessionStorageNamespace(entry.first, entry.second.get());
}

if (params.guest\_delegate) {
BrowserPluginGuest::Create(new\_contents.get(), params.guest\_delegate);
}

new\_contents->Init(params);
return new\_contents;
}