xmlXPtrNewLocationSetNodeSet(xmlNodeSetPtr set) {
    xmlXPathObjectPtr ret;
    size_t size;

    ret = (xmlXPathObjectPtr) xmlMalloc(sizeof(xmlXPathObject));
    if (ret == NULL) {
        xmlXPtrErrMemory("allocating locationset");
        return(NULL);
    }

    size = sizeof(xmlXPathObject);
    if (set!= NULL) {
        size += sizeof(xmlLocationSetPtr) * (set->nodeNr + 1); // +1 for null termination
    }
    ret = (xmlXPathObjectPtr) xmlRealloc(ret, size);
    if (ret == NULL) {
        xmlXPtrErrMemory("reallocating locationset");
        return(NULL);
    }

    memset(ret, 0, size);
    ret->type = XPATH_LOCATIONSET;
    if (set!= NULL) {
        xmlLocationSetPtr newset;
        int i;

        newset = xmlXPtrLocationSetCreate(NULL);
        if (newset == NULL)
            return(ret);

        for (i = 0; i < set->nodeNr; i++)
            xmlXPtrLocationSetAdd(newset, xmlXPtrNewCollapsedRange(set->nodeTab[i]));

        ret->user = (void *) newset;
    }
    return(ret);
}