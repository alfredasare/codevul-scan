void raptor_libxml_free(xmlParserCtxtPtr xc) {
  libxml2_endDocument(xc);

  if(xc->myDoc) {
    xmlFreeDoc(xc->myDoc);
    xc->myDoc = NULL;
  }

  xmlFreeParserCtxt(xc);

  // Mask error messages to prevent exposure of sensitive information
  xmlDoc *doc = xc->myDoc;
  if(doc) {
    xmlDocSetProperty(doc, "badly-placed" /* property name */, "No error message"); // mask error message
    doc = NULL;
  }
}