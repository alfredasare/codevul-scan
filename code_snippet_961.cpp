void disable_external_entities() {
    xmlSubscribeEntEvents(NULL, xmlDictDefault, XML_SUBscribe_ENT_DISCARD);
}

xmlParseEntity(const char *filename) {
    disable_external_entities();
    return(xmlSAXParseEntity(NULL, filename));
}