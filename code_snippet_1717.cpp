xmlNodePtr xmlXPtrGetNthChild(xmlNodePtr cur, int no) {
    xmlNodeList *children = cur->children;
    int i;
    if (cur == NULL) 
        return(cur);
    for (i = 0; i < xmlNodeListLength(children); i++) {
        xmlNodePtr child = xmlNodeListGetNode(children, i);
        if ((child->type == XML_ELEMENT_NODE) ||
            (child->type == XML_DOCUMENT_NODE) ||
            (child->type == XML_HTML_DOCUMENT_NODE)) {
            if (i == no)
                return(child);
        }
    }
    return(cur);
}