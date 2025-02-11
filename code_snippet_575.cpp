static void testInterfaceEmptyMethodMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TestInterfaceNode* impl = V8TestInterfaceNode::toImpl(info.Holder());
    v8::Local<v8::Value> result = impl->testInterfaceEmptyMethod();
    if (result.IsObject()) {
        v8SetReturnValueFast(info, result);
    } else {
        v8SetReturnValueFast(info, v8::Null());
    }
}