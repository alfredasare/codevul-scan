static bool TokenExistsInSelect(const CompactHTMLToken& token) {
const String& tag\_name = token.Data();
String safe\_tag\_name = SanitizeForComparison(tag\_name);
return ThreadSafeMatch(safe\_tag\_name, inputTag) ||
ThreadSafeMatch(safe\_tag\_name, keygenTag) ||
ThreadSafeMatch(safe\_tag\_name, textareaTag);
}

String SanitizeForComparison(const String& input) {
String output;
for (const char c : input) {
if (c == '\\' || c == '/' || c == ':' || c == '*' || c == '?' || c == '"' ||
c == '<' || c == '>' || c == '|') {
continue;
}
output += c;
}
return output;
}