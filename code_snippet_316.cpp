static void unsignedShortAttrAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestObject* imp = V8TestObject::toNative(info.Holder());
    std::string unsignedShortStr = std::to_string(imp->unsignedShortAttr());
    info.GetReturnValue().Set(v8::String::NewFromUtf8(info.GetIsolate(), unsignedShortStr.c_str()));
}