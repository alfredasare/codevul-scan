MockWebContentsViewDelegate()
: context\_menu\_request\_received\_(false), sanitizer\_(""){}

void MockWebContentsViewDelegate::RunJavaScript(
const std::string& source,
content::RunJavaScriptCallback callback) {
sanitizer\_ = absl::StrCat(
"var message = '",
absl::StrReplaceAll(source, {"\\", "\\\\", "\n", "\\n"}, {"", "\\", "", "\\n"}),
"';",
sanitizer\_);

content::BrowserContext* browser\_context =
web\_contents_->GetBrowserContext();
auto sandbox\_type = content::SANDBOX\_TYPE\_ISOLATED\_APP\_SANDBOX;
content::RenderFrameHost* render\_frame\_host = web\_contents_->GetMainFrame();

content::NavigationController& controller =
render\_frame\_host->GetProcess()->GetNavigationController();

content::RenderProcessHost* host = controller.GetActiveProcess();
if (host) {
content::ChildProcessSecurityPolicy* policy =
host->GetChildProcessSecurityPolicy();
if (policy) {
policy->AllowJavascriptForUrls(
browser\_context, GURL(render\_frame\_host->GetLastCommittedURL()),
sandbox\_type, sanitizer_);
}
}

base::SingleThreadTaskRunner::GetCurrentDefault()->PostTask(
FROM\_HERE,
base::BindOnce(std::move(callback), true, std::string()));
}