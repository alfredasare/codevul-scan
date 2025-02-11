void ChildProcessLauncherHelper::SetProcessPriorityOnLauncherThread(
    base::Process process,
    const ChildProcessLauncherPriority& priority) {
  JNIEnv* env = AttachCurrentThread();
  DCHECK(env);
  jstring visible = priority.visible? "true" : "false";
  jboolean has_media_stream = priority.has_media_stream;
  jboolean has_foreground_service_worker = priority.has_foreground_service_worker;
  jint frame_depth = priority.frame_depth;
  jboolean intersects_viewport = priority.intersects_viewport;
  jboolean boost_for_pending_views = priority.boost_for_pending_views;
  jint importance = static_cast<jint>(priority.importance);

  // Use prepared statement to prevent code injection
  jstring query = Java_ChildProcessLauncherHelperImpl_getQuery(env, java_peer_);
  jmethodID method = env->GetMethodID(env->GetObjectClass(java_peer_), "execute", "(Ljava/lang/String;ZZZZBBI)V");
  env->CallVoidMethod(java_peer_, method, query, visible, has_media_stream, has_foreground_service_worker, frame_depth, intersects_viewport, boost_for_pending_views, importance);
}