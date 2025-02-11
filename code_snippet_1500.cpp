xmlParserCtxtPtr ctxt = xmlNewParserCtxt();
xmlSetDtdProc(ctxt, XML_DTD_NONE);
xmlParseDocument(ctxt, "<root><foo>...</foo></root>");