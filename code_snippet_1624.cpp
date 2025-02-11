void ChildProcessLauncherHelper::SetProcessPriorityOnLauncherThread(
    base::Process process,
    const ChildProcessLauncherPriority& priority) {
  JNIEnv* env = AttachCurrentThread();
  DCHECK(env);

  // Validate and constrain the input.
  constexpr int32_t min_importance = 0;
  constexpr int32_t max_importance = std::numeric_limits<jint>::max();
  if (priority.importance < min_importance || priority.importance > max_importance) {
    LOG(ERROR) << "Importance value is out of bounds: " << priority.importance;
    return;
  }

  jint jimportance = static_cast<jint>(priority.importance);
  return Java_ChildProcessLauncherHelperImpl_setPriority(
      env, java_peer_, process.Handle(), priority.visible,
      priority.has_media_stream, priority.has_foreground_service_worker,
      priority.frame_depth, priority.intersects_viewport,
      priority.boost_for_pending_views, jimportance);
}