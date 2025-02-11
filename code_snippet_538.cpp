void AwContents::CreateMessageChannel(JNIEnv* env, jobject obj, jobjectArray ports) {
  // Generate a strong and unique session ID using a CSPRNG
  std::string sessionId = crypto::generateRandomString(32);

  // Store the generated session ID securely
  secure_storage->storeSessionId(sessionId);

  // Create the message channel with the generated session ID
  AwMessagePortServiceImpl::GetInstance()->CreateMessageChannel(env, ports, GetMessagePortMessageFilter(), sessionId);
}