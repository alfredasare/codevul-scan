c++
void WasmCompileStreamingImpl(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  ScriptState* script_state = ScriptState::ForRelevantRealm(args);

  v8::Local<v8::Function> compile_callback =
      v8::Function::New(isolate, CompileFromResponseCallback);

  // Sanitize the input data before using it to prevent XSS attacks.
  v8::String::Utf8Value input_data(isolate, args[0]);
  std::string sanitized_data = sanitize_input(*input_data);

  V8SetReturnValue(args, ScriptPromise::Cast(script_state,
                                            v8::Script::Compile(script_state,
                                                               v8::Just(isolate,
                                                                        v8::String::NewFromUtf8(isolate, sanitized_data.c_str(),
                                                                                                v8::NewStringType::kNormal)
                                                                        )
                                                               )
                                            )
                             .Then(compile_callback)
                             .V8Value());
}