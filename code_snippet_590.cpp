EncodedJSValue JSC_HOST_CALL jsTestObjPrototypeFunctionMethodWithOptionalStringIsUndefined(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSTestObj::s_info))
        return throwVMTypeError(exec);
    JSTestObj* castedThis = jsCast<JSTestObj*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSTestObj::s_info);
    TestObj* impl = static_cast<TestObj*>(castedThis->impl());
    String str = exec->argument(0).isUndefined() ? String() : exec->argument(0).toString(exec)->value(exec);
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    impl->methodWithOptionalStringIsUndefined(str);
    return JSValue::encode(jsUndefined());
}