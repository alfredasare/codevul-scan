v8::Handle<v8::Value> ToV8(TestObject* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (!impl || !impl->IsKindOf(v8::Local<v8::FunctionTemplate>::New(isolate, TestObject::constructor))) {
        return v8::Null(isolate);
    }
    return ToV8Internal(impl, creationContext, isolate);
}

v8::Handle<v8::Value> ToV8Internal(TestObject* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    // Previously named 'toV8NoInline'
    // ... (the rest of the original function body)
}