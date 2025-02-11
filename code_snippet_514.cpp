JSValue jsTestObjReflectedCustomBooleanAttr(ExecState* exec, JSValue slotBase, const Identifier&)
{
    if (!slotBase.isObject()) {
        reportException(exec, createTypeError(exec, "Expected an object"));
        return jsNull();
    }

    JSTestObj* castedThis = jsCast<JSTestObj*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    TestObj* impl = static_cast<TestObj*>(castedThis->impl());

    constexpr size_t numAllowedValues = 3;
    JSC::JSValue allowedValues[numAllowedValues] = { jsNumber(1), jsNumber(42), jsString("valid_string") };

    bool found = false;
    for (size_t i = 0; i < numAllowedValues; ++i) {
        if (slotBase == allowedValues[i]) {
            found = true;
            break;
        }
    }

    if (found) {
        JSValue result = jsBoolean(impl->hasAttribute(WebCore::HTMLNames::customContentBooleanAttrAttr));
        return result;
    } else {
        reportException(exec, createRangeError(exec, "Input value is not allowed"));
        return jsNull();
    }
}