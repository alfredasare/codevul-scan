void OmniboxEditModel::GetDataForURLExport(GURL* url,
                                         base::string16* title,
                                         gfx::Image* favicon) {
  GURL calculatedUrl = CurrentMatch(NULL).destination_url;
  // Validate the input
  if (!calculatedUrl.is_valid()) {
    *url = GURL(); // or set a default value
    return;
  }

  *url = calculatedUrl;

  if (*url == delegate_->GetURL()) {
    content::WebContents* web_contents = controller_->GetWebContents();
    *title = web_contents->GetTitle();
    *favicon = FaviconTabHelper::FromWebContents(web_contents)->GetFavicon();
  }
}