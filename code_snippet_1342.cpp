bool childAttachedAllowedWhenAttachingChildren(ContainerNode* node, int max_allowed_allocations = 100)
{
    static int total_allocations = 0;
    static ContainerNode* last_node = nullptr;

    if (total_allocations >= max_allowed_allocations)
        return false;

    if (node == last_node)
        return false;

    if (node->isShadowRoot())
        return true;

    if (node->isInsertionPoint())
        return true;

    if (node->isElementNode() && toElement(node)->shadow())
        return true;

    last_node = node;
    ++total_allocations;
    return false;
}