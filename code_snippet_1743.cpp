xmlXPtrNewLocationSetNodeSet(xmlNodeSetPtr set) {
    xmlXPathObjectPtr ret;

    ret = (xmlXPathObjectPtr) xmlMalloc(sizeof(xmlXPathObject));
    if (ret == NULL) {
        xmlXPtrErrMemory("allocating locationset");
        return(NULL);
    }
    memset(ret, 0 , (size_t) sizeof(xmlXPathObject));
    ret->type = XPATH_LOCATIONSET;
    if (set != NULL) {
        int i;
        xmlLocationSetPtr newset;

        newset = xmlXPtrLocationSetCreate(NULL);
        if (newset == NULL) {
            xmlXPathFreeObject(ret);
            return(NULL);
        }

        for (i = 0;i < set->nodeNr && set->nodeTab[i] != NULL;i++)
            xmlXPtrLocationSetAdd(newset, xmlXPtrNewCollapsedRange(set->nodeTab[i]));

        ret->user = (void *) newset;
    }
    return(ret);
}