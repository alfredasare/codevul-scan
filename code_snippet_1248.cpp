c++
void RenderThreadImpl::RecordAction(const base::UserMetricsAction& action) {
  std::string formatted_action = base::StringPrintf("%s", action.str().c_str());
  Send(new ViewHostMsg_UserMetricsRecordAction(formatted_action));
}