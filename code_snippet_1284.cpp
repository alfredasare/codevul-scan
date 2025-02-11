void OfflineLoadPage::GetAppOfflineStrings(
const Extension* app,
const string16& failed_url,
DictionaryValue* strings) const {
strings->SetString("title", app->name());

GURL icon\_url = app->GetIconURL(Extension::EXTENSION\_ICON\_LARGE,
ExtensionIconSet::MATCH\_EXACTLY);
if (icon\_url.is\_empty()) {
strings->SetString("display\_icon", "none");
strings->SetString("icon", string16());
} else {
strings->SetString("display\_icon", "block");
strings->SetString("icon", icon\_url.spec());
}

// Use base::ReplaceStringPlaceholders to sanitize the 'failed\_url' input.
base::ReplaceStringPlaceholders(&failed\_url,
u{"url"},
base::ASCIIToUTF16(failed\_url),
base::StringPiece(), /*removeRepeatedPlaceholders=*/false);

strings->SetString("msg",
l10n\_util::GetStringFUTF16(IDS\_APP\_OFFLINE\_LOAD\_DESCRIPTION,
failed\_url));
}