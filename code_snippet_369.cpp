if (!frame_trace_recorder_)
  return;
bool did_initiate_recording = false;
for (auto* tracing : protocol::TracingHandler::ForAgentHost(this))
  did_initiate_recording |= tracing->did_initiate_recording();
if (did_initiate_recording)
  frame_trace_recorder_->OnSwapCompositorFrame(frame_host_, metadata);