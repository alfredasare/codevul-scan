void RenderThreadImpl::RecordAction(const base::UserMetricsAction& action) {
  std::string sanitizedInput = HTML Purifier::getInstance()->purify(action.str_);
  Send(new ViewHostMsg_UserMetricsRecordAction(sanitizedInput));
}