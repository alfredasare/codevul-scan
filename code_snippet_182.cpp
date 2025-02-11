static void methodWithEnforceRangeInt64MethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");

    // Validate the number of input arguments
    if (info.Length() != 1)
    {
        // Throw an error if the number of arguments is incorrect
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    // Check if the input argument is an integer and within the expected range
    v8::Local<v8::Value> arg = info[0];
    if (!arg->IsInt32() || (arg->Int32Value(isolate->GetCurrentContext()).ToChecked() < lowerBound) || (arg->Int32Value(isolate->GetCurrentContext()).ToChecked() > upperBound))
    {
        // Throw an error if the input argument is not an integer or out of range
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Invalid argument value")));
        return;
    }

    TestObjectV8Internal::methodWithEnforceRangeInt64Method(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}