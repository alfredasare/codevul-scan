void BeginSpecificTrace(const std::string& filter) {
    event_watch_notification_ = 0;
    TraceConfig trace_config(filter, "");
    TraceLog* trace_log = TraceLog::GetInstance();
    if (trace_log) {
        trace_log->SetEnabled(trace_config, TraceLog::RECORDING_MODE);
    }
}