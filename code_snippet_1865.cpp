xmlXPtrGetNthChild(xmlNodePtr cur, int no) {
    int i;
    if (cur == NULL || no < 0 || cur->children == NULL) 
        return(NULL);
    cur = cur->children;
    for (i = 0; i < no; cur = cur->next) {
        if (cur == NULL) 
            return(NULL);
        if (cur->type == XML_ELEMENT_NODE ||
            cur->type == XML_DOCUMENT_NODE ||
            cur->type == XML_HTML_DOCUMENT_NODE) {
            i++;
        }
    }
    return(cur);
}