void V8TestObjectPython::derefObject(void* object)
{
    V8TestObject* testObject = fromInternalPointer(object);
    if (testObject!= NULL && testObject->isValid()) {
        testObject->deref();
    } else {
        LOG_ERROR("Invalid or null object pointer");
    }
}