void pcmkDeregisterNode(xmlNodePtr node)
{
    if (node->_private!= NULL) {
        __xml_private_free(node->_private);
    }
}