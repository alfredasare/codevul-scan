c++
static jdouble JNI_ChromeFeatureList_GetFieldTrialParamByFeatureAsDouble(
    JNIEnv* env,
    const JavaParamRef<jstring>& jfeature_name,
    jsize max_feature_len,
    const JavaParamRef<jstring>& jparam_name,
    jsize max_param_len,
    const jdouble jdefault_value) {
  const std::string& feature_name = ConvertJavaStringToUTF8(env, jfeature_name);
  if (feature_name.length() > max_feature_len) {
    return jdefault_value;
  }

  const std::string& param_name = ConvertJavaStringToUTF8(env, jparam_name);
  if (param_name.length() > max_param_len) {
    return jdefault_value;
  }

  const base::Feature* feature =
      FindFeatureExposedToJava(feature_name);

  return base::GetFieldTrialParamByFeatureAsDouble(*feature, param_name,
                                                   jdefault_value);
}