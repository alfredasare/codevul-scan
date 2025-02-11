static void readonlyTestInterfaceEmptyAttributeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Local<v8::Object> holder = info.Holder();
    TestInterfaceNode* impl = V8TestInterfaceNode::toImpl(holder);
    std::optional<void*> ptr = impl->readonlyTestInterfaceEmptyAttribute();
    if (ptr.has_value()) {
        v8SetReturnValueFast(info, *ptr);
    } else {
        v8SetReturnValueUndefined(info); // or throw an exception if needed
    }
}