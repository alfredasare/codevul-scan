xmlAttrPtr get_attribute_ex(xmlAttrPtr node, const char *name, const char *ns)
{
    // Check for NULL and empty strings
    if (!name || !*name || (!ns || !*ns)) {
        return NULL;
    }

    while (node != NULL) {
        if (attr_is_equal_ex(node, name, ns)) {
            return node;
        }
        node = node->next;