#include <filesystem>
namespace fs = std::filesystem;

static void testInterfaceEmptyMethodMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TestInterfaceNode* impl = V8TestInterfaceNode::toImpl(info.Holder());

    // Get user input
    std::string userInput = info[0]->ToString();

    // Construct the final path
    fs::path intendedDir("/path/to/intended/directory");
    fs::path filePath = intendedDir / userInput;

    // Sanitize the file path
    fs::path sanitizedPath = fs::canonical(filePath);

    // Ensure the sanitized path is within the intended directory
    if (sanitizedPath.is_relative() && (sanitizedPath.parent_path() == intendedDir)) {
        v8SetReturnValueFast(info, impl->testInterfaceEmptyMethod(sanitizedPath), impl);
    } else {
        // Return an error or handle the invalid path accordingly
        v8SetReturnValueFast(info, v8::Null(), impl);
    }
}