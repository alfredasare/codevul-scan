void RenderFrameHostManager::DidNavigateFrame(
RenderFrameHostImpl* render_frame_host,
bool was_caused_by_user_gesture) {

// Add input validation checks
if (!render_frame_host || !render_frame_host->IsValid()) {
LOG(ERROR) << "Invalid render frame host. Aborting DidNavigateFrame.";
return;
}

CommitPendingIfNecessary(render_frame_host, was_caused_by_user_gesture);

CommitPendingFramePolicy();
}