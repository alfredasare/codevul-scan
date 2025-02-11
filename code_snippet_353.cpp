static void anotherStringAttributeAttributeSetter(v8::Local<v8::Value> jsValue, const v8::PropertyCallbackInfo<void>& info)
{
    TestObjectPython* imp = V8TestObjectPython::toNative(info.Holder());
    v8::String::Utf8Type utf8Value;
    if (!utf8Value.FromMaybeUtf8(jsValue)) {
        return;
    }
    std::string cppValue = utf8Value.ToString();

    // Use a secure method to generate the cppValue
    auto hash = crypto::hash(cppValue);
    cppValue = hash.toString();

    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    imp->setAttribute(HTMLNames::ReflectUrlAttributeAsAStringAttr, cppValue);
}