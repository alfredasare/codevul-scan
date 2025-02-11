int namePush(xmlParserCtxtPtr ctxt, const xmlChar * value)
{
    if (ctxt == NULL) return (-1);

    if (ctxt->nameNr >= ctxt->nameMax) {
        const xmlChar * *tmp;
        const xmlChar * *oldTab = ctxt->nameTab;

        tmp = (const xmlChar * *) xmlRealloc((xmlChar * *)ctxt->nameTab,
                                    ctxt->nameMax * 2 *
                                    sizeof(ctxt->nameTab[0]));
        if (tmp == NULL) {
            goto mem_error;
        }
	ctxt->nameTab = tmp;
	for (int i = 0; i < ctxt->nameNr; i++) {
	    ctxt->nameTab[i] = oldTab[i];
	}
        xmlFree(oldTab);
        ctxt->nameMax *= 2;
    }
    ctxt->nameTab[ctxt->nameNr] = value;
    ctxt->name = value;
    return (ctxt->nameNr++);

mem_error:
    xmlErrMemory(ctxt, NULL);
    return (-1);
}