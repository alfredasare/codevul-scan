static void corsSettingAttributeAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestObjectPython* imp = V8TestObjectPython::toNative(info.Holder());
    String resultValue = imp->fastGetAttribute(HTMLNames::corssettingattributeAttr);
    if (resultValue.isNull() || resultValue != "anonymous" && resultValue != "use-credentials") {
        resultValue = "anonymous";
    }
    v8SetReturnValueString(info, resultValue, info.GetIsolate());
}