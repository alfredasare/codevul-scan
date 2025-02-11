ExtensionDevToolsInfoBarDelegate::ExtensionDevToolsInfoBarDelegate(
const std::string& client\_name, content::WebContents* client\_host)
: ConfirmInfoBarDelegate(),
client\_name\_(client\_name),
client\_host\_(client\_host) {}