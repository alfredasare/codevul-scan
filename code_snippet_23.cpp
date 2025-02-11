void V8TestObjectPython::derefObject(void* object)
{
    if (object != nullptr) {
        fromInternalPointer(object)->deref();
    }
}