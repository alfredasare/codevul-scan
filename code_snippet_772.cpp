static void longMethodMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TestObject* imp = V8TestObject::toNative(info.Holder());
    int result = imp->longMethod();
    if (result >= INT_MIN && result <= INT_MAX) {
        v8SetReturnValueInt(info, result);
    } else {
        // Handle error case
    }
}