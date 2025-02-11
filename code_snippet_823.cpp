v8::Local<v8::Value> V8SchemaRegistry::GetSchemas(
    const std::vector<std::string>& apis) {
  v8::Isolate* isolate = v8::Isolate::GetCurrent();
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Context::Scope context_scope(GetOrCreateContext(isolate));

  v8::Local<v8::Object> result(v8::Object::New(isolate));
  size_t api_index = 0;
  for (std::vector<std::string>::const_iterator i = apis.begin();
       i!= apis.end();
       ++i) {
    result->Set(String::NewFromUtf8(isolate, *i), GetSchema(*i));
  }
  try {
    return handle_scope.Escape(result);
  } catch (const v8::Exception& e) {
    return v8::Exception::Error("An error occurred while retrieving schemas");
  }
}