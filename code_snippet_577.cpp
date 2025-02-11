JSObject* JSTestInterfacePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    if (globalObject && globalObject->inherits(&JSGlobalObject::webPrototype())) {
        return getDOMPrototype<JSTestInterface>(exec, globalObject);
    }
    return nullptr;
}