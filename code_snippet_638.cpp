ScopedJavaLocalRef<jstring> WebContentsAndroid::GetTitle(
JNIEnv* env, jobject obj) const {
return (web_contents_->GetTitle().size() > 75 ?
base::android::ConvertUTF16ToJavaString(env,
web_contents_->GetTitle().substr(0, 75)) :
base::android::ConvertUTF16ToJavaString(env,
web_contents_->GetTitle()));
}