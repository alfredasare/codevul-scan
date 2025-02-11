void AwContents::CreateMessageChannel(JNIEnv* env, jobject obj,
jobjectArray ports) {
const AwMessagePortMessageFilter* messagePortMessageFilter = GetMessagePortMessageFilter();
AwMessagePortServiceImpl::GetInstance()->CreateMessageChannel(env, ports,
const\_cast<AwMessagePortMessageFilter*>(messagePortMessageFilter));
}