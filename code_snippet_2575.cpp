static std::mutex feature_list_mutex;

static jboolean JNI_ChromeFeatureList_IsInitialized(
    JNIEnv* env,
    const JavaParamRef<jclass>& clazz) {
  std::unique_lock<std::mutex> lock(feature_list_mutex);
  base::FeatureList* feature_list = base::FeatureList::GetInstance();
  return feature_list != nullptr;
}