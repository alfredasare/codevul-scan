static jdouble JNI_ChromeFeatureList_GetFieldTrialParamByFeatureAsDouble(
    JNIEnv* env,
    const JavaParamRef<jstring>& jfeature_name,
    const JavaParamRef<jstring>& jparam_name,
    const jdouble jdefault_value) {
  // Validate input strings
  if (!IsValidJavaString(env, jfeature_name) ||!IsValidJavaString(env, jparam_name)) {
    return 0.0;
  }

  const base::Feature* feature =
      FindFeatureExposedToJava(ConvertJavaStringToUTF8(env, jfeature_name));
  const std::string& param_name = ConvertJavaStringToUTF8(env, jparam_name);
  return base::GetFieldTrialParamByFeatureAsDouble(*feature, param_name, jdefault_value);
}

bool IsValidJavaString(JNIEnv* env, const JavaParamRef<jstring>& jstring) {
  jstring jstr = jstring.get();
  jsize len = env->GetStringLength(jstr);
  for (int i = 0; i < len; i++) {
    jchar c = env->GetStringChar(jstr, i);
    if (!isalnum(c) &&!isgraph(c) &&!ispunct(c)) {
      return false;
    }
  }
  return true;
}