raptor_libxml_free(xmlParserCtxtPtr xc) {
  if (!xc) {
    // Log error message and return or handle appropriately
    fprintf(stderr, "Error: Invalid input. Input cannot be null.\n");
    return;
  }

  libxml2_endDocument(xc);

  if(xc->myDoc) {
    xmlFreeDoc(xc->myDoc);
    xc->myDoc = NULL;
  }

  xmlFreeParserCtxt(xc);
}