WebLocalFrameImpl::ExecuteScriptInIsolatedWorldAndReturnValue(
    int world_id,
    const WebScriptSource& source_in) {
  DCHECK(GetFrame());
  CHECK_GT(world_id, 0);
  CHECK_LT(world_id, DOMWrapperWorld::kEmbedderWorldIdLimit);

  try {
    return GetFrame()->GetScriptController().ExecuteScriptInIsolatedWorld(
        world_id, source_in);
  } catch (const std::exception& e) {
    VLOG(1) << "Error executing script";
    return nullptr;
  }
}