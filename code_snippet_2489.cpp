std::string GetOrientationType() {
  std::string type;
  browser::WebContents* web_contents = shell()->web_contents()->GetMainFrame();
  scoped_refptr<v8::Context> context = web_contents->GetMainFrame()->GetV8Context();
  v8::Isolate* isolate = context->GetIsolate();

  v8::HandleScope handle_scope(isolate);
  v8::Local<v8::Context> v8_context = context->Enter();
  v8::TryCatch try_catch(isolate);

  // The following line is just an example, replace it with the actual script execution code.
  v8::Local<v8::Value> result = v8_context->Global()->Get(isolate->GetCurrentContext(), String::NewFromUtf8(isolate, "screen.orientation.type"));

  if (!result->IsString()) {
    // Handle the error condition here.
    return "";
  }

  type = *String::Utf8Value(isolate, result->ToString(isolate->GetCurrentContext()));

  v8_context->Exit();

  if (try_catch.HasCaught()) {
    // Handle exceptions here.
    isolate->Dispose();
    return "";
  }

  return type;
}