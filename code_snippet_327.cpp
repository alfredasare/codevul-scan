JSTestMediaQueryListListenerConstructor::JSTestMediaQueryListListenerConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
: DOMConstructorObject(structure, globalObject)
{
String userInput = globalObject->getUserInput();
userInput = userInput.trim().replace(QRegExp("[^a-zA-Z0-9_-]"), QString());
processSanitizedInput(userInput);
}