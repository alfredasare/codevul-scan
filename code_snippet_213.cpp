static void treatReturnedNullStringAsNullStringAttributeAttributeSetter(v8::Local<v8::Value> jsValue, const v8::PropertyCallbackInfo<void>& info)
{
    TestObjectPython* imp = V8TestObjectPython::toNative(info.Holder());

    // Sanitize and validate the user-supplied input
    std::string cppValue;
    if (jsValue->IsString()) {
        v8::String::Utf8Value str(jsValue);
        cppValue = *str;
        boost::replace_all(cppValue, "\", "");
        cppValue.erase(std::remove_if(cppValue.begin(), cppValue.end(),
            [](char c) { return!isalnum(c) && c!=' '; }), cppValue.end());
    }

    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, cppValue, jsValue);
    imp->setTreatReturnedNullStringAsNullStringAttribute(cppValue);
}