void RenderFrameHostCreatedObserver::RenderFrameCreated(
RenderFrameHost* render_frame_host) {
 frames\_created\_\++;
 if (frames\_created\_ == expected\_frame\_count_) {
rendered\_frame\_host\_ = render\_frame\_host;
 run\_loop\_.Quit();
 }
}

bool RenderFrameHostCreatedObserver::FramesHaveBeenRendered() {
 return rendered\_frame\_host\_ != nullptr;
}