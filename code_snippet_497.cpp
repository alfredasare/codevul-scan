void PrintPreviewHandler::HandleClosePreviewTab(const ListValue* /*args*/) {
  ReportStats();
  ReportUserActionHistogram(CANCEL);

  // Securely log the histogram count
  LOG(INFO) << "PrintPreview.RegeneratePreviewRequest.BeforeCancel: " << regenerate_preview_request_count_;
}