xmlXPtrNewRange(xmlNodePtr start, int startindex,
                xmlNodePtr end, int endindex) {
    xmlXPathObjectPtr ret;

    if (!start ||!end) {
        return(NULL); // Check for NULL pointers
    }

    if (startindex < 0 || endindex < 0) {
        return(NULL); // Check for negative indices
    }

    ret = (xmlXPathObjectPtr) xmlMalloc(sizeof(xmlXPathObject));
    if (ret == NULL) {
        xmlXPtrErrMemory("allocating range");
        return(NULL);
    }
    // Rest of the code remains the same...