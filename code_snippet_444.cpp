static void staticStringAttrAttributeSetter(v8::Local<v8::Value> jsValue, const v8::PropertyCallbackInfo<void>& info)
{
    if (jsValue->IsString())
    {
        V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, cppValue, jsValue);
        TestObject::setStaticStringAttr(cppValue);
    }
    else
    {
        // Handle error case for non-string input
        // ...
    }
}