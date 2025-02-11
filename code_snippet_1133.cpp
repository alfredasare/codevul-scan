int xmlThrDefSaveNoEmptyTags(int v) {
    int ret;
    xmlMutexLock(xmlThrDefMutex);

    if (v < 0 || v >= XML_MAX_TAG_LENGTH) {
        // Handle invalid input value, e.g., log an error or return an error code
        //...
    } else {
        ret = xmlSaveNoEmptyTagsThrDef;
        xmlSaveNoEmptyTagsThrDef = v;
    }

    xmlMutexUnlock(xmlThrDefMutex);
    return ret;
}