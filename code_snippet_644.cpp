~~~cpp
ExtensionFunctionDispatcher::~ExtensionFunctionDispatcher() {
    for (auto& function : functions) {
        delete function.second;
    }
    functions.clear();
}
~~~