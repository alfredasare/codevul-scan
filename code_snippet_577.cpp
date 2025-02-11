void WasmCompileStreamingImpl(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  ScriptState* script_state = ScriptState::ForRelevantRealm(args);

  v8::Local<v8::String> user_input = args[0].As<v8::String>();

  v8::String::Utf8Value utf8_user_input(user_input);
  std::string sanitized_user_input = v8::String::ToUtf8Checked(*utf8_user_input);

  v8::Local<v8::Function> compile_callback = v8::Function::New(isolate, CompileFromResponseCallback);

  V8SetReturnValue(args, ScriptPromise::Cast(script_state, args[0])
                           .Then(compile_callback)
                           .V8Value());
}