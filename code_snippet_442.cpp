void V8Console::groupCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    std::string input = info[0].As<String16>()->Utf8Value();
    boost::replace_all(input, "&", "&#38;"); // Escape ampersands
    boost::replace_all(input, "&apos;", "&#x27;"); // Escape apostrophes
    boost::replace_all(input, "&quot;", "&#x22;"); // Escape double quotes
    boost::replace_all(input, "&lt;", "&#60;"); // Escape less-than symbols
    boost::replace_all(input, "&gt;", "&#62;"); // Escape greater-than symbols
    ConsoleHelper(info).reportCallWithDefaultArgument(ConsoleAPIType::kStartGroup, String16("console.group").Append(String16(input)));
}