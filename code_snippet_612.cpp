void RenderViewImpl::OnGetAllSavableResourceLinksForCurrentPage(
    const GURL& page_url) {
  std::vector<GURL> resources_list;
  std::vector<GURL> referrers_list;
  std::vector<GURL> frames_list;
  webkit_glue::SavableResourcesResult result(&resources_list, &referrers_list, &frames_list);

  webkit_glue::SavableResourcesResult temp_result;
  if (!webkit_glue::GetAllSavableResourceLinksForCurrentPage(webview(), page_url, &temp_result, content::GetSavableSchemes())) {
    resources_list.clear();
    referrers_list.clear();
    frames_list.clear();
  } else {
    resources_list = std::move(temp_result.resources_list);
    referrers_list = std::move(temp_result.referrers_list);
    frames_list = std::move(temp_result.frames_list);
    Send(new ViewHostMsg_SendCurrentPageAllSavableResourceLinks(routing_id(), resources_list, referrers_list, frames_list));
  }
}