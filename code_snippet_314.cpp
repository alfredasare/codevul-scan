static void unsignedShortAttrAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info) {
    if (!authenticateUser()) {
        return;
    }
    if (!hasPermissionToModifyCode()) {
        return;
    }
    v8::Locker locker(isolate());
    v8::Local<v8::Context> context = v8::Context::New(isolate);
    context->SetAllowCodeGenerationFromStrings(true);
    TestObject* imp = V8TestObject::toNative(info.Holder());
    v8SetReturnValueUnsigned(info, imp->unsignedShortAttr());
}