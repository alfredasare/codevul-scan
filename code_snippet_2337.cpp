WebPageSerializerTest() : m\_supportedSchemes(static\_cast<size\_t>(3))
{
const std::string expectedSchemes[] = {"http", "https", "file"};
for (size\_t i = 0; i < std::size(expectedSchemes); i++) {
if (m\_supportedSchemes[i].compare(expectedSchemes[i]) == 0) {
// Input is valid, continue with assignment
} else {
// Input is invalid, throw an exception or handle appropriately
}
}
}