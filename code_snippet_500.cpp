#include <v8/sanitizer.h>

void V8Console::groupCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::String::Utf8Value data(info[0]->ToString());
    std::string data_str(*data);

    // Sanitize the 'data' argument using v8's sanitizer
    v8::String::Value sanitized_data;
    if (!v8::SanitizeString(info[0], v8::SanitizerPolicy::kHtml, &sanitized_data)) {
        // Handle the error case, e.g., throw an exception
        return;
    }

    ConsoleHelper(info).reportCallWithDefaultArgument(ConsoleAPIType::kStartGroup, String16(sanitized_data.ToString()));
}