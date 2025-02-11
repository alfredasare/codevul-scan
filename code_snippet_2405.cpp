static jboolean JNI_ChromeFeatureList_IsInitialized(JNIEnv* env, const JavaParamRef<jclass>& clazz) {
  if (!env->IsSameObject(clazz, env->GetObjectClass("com/google/chrome/FeatureList"))) {
    return JNI_FALSE;
  }
  try {
    return !!base::FeatureList::GetInstance();
  } catch (const std::exception& e) {
    LOG(ERROR) << "Error initializing feature list: " << e.what();
    return JNI_FALSE;
  }
}