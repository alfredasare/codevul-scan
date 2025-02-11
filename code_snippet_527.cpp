ScopedJavaLocalRef<jstring> WebContentsAndroid::GetTitle(JNIEnv* env, jobject obj) const {
  jstring title = web_contents_->GetTitle();
  if (!title) {
    return env->NewStringUTF("Title not available");
  }
  return env->NewStringUTF(title); // Defensive copy
}