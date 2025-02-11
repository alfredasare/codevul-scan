static v8::Handle<v8::Value> IsExtensionProcess(const v8::Arguments& args) {
  if (!args.IsObject()) {
    throw v8::TypeError::New(v8::String::New("Expected an object"));
  }

  v8::Local<v8::Object> obj = args.GetHandle<v8::Object>();
  if (!obj->HasOwnProperty(v8::String::New("extension_dispatcher"))) {
    throw v8::TypeError::New(v8::String::New("Missing 'extension_dispatcher' property"));
  }

  v8::Local<v8::Object> extension_dispatcher = obj->Get(v8::String::New("extension_dispatcher"));
  if (!extension_dispatcher->IsObject()) {
    throw v8::TypeError::New(v8::String::New("Expected 'extension_dispatcher' to be an object"));
  }

  ExtensionImpl* v8_extension = GetValidatedExtensionImpl(extension_dispatcher);
  return v8::Boolean::New(v8_extension->extension_dispatcher_->is_extension_process());
}

ExtensionImpl* GetValidatedExtensionImpl(v8::Local<v8::Object> obj) {
  // Implement additional validation logic here
  // For example, check if the object has a specific method or property
  //...
  return new ExtensionImpl(obj);
}