bool childAttachedAllowedWhenAttachingChildren(ContainerNode* node, ContainerNode* parent)
{
    if (node->isShadowRoot() || node->isInsertionPoint())
        return true;

    if (node->isElementNode() && toElement(node)->shadow() && parent->canAttachChild(toElement(node)))
        return true;

    return false;
}

bool ContainerNode::canAttachChild(Element* child) {
    return true;
}