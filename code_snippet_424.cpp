AXNodeObject* AXNodeObject::create(Node* node, AXObjectCacheImpl& axObjectCache) {
    if (node == nullptr) {
        return nullptr;
    }
    return new AXNodeObject(node, axObjectCache);
}