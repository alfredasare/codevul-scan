static void overloadedMethodDMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    // Whitelist of allowed input values or patterns
    const std::set<std::string> allowedCallbacks = {"allowedCallback1", "allowedCallback2"};

    // Validate input
    if (!allowedCallbacks.count(info.GetCallbackName())) {
        return;
    }

    // Sanitized input is allowed, proceed with the method call
    TestObjectPythonV8Internal::overloadedMethodDMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}