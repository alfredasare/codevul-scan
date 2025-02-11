namePush(xmlParserCtxtPtr ctxt, const xmlChar * value)
{
    if (ctxt == NULL) return (-1);

    if (ctxt->nameNr >= ctxt->nameMax) {
        const xmlChar * *tmp;
        tmp = (const xmlChar * *) xmlRealloc((xmlChar * *)ctxt->nameTab,
                                    ctxt->nameMax * 2 *
                                    sizeof(ctxt->nameTab[0]));
        if (tmp == NULL) {
            goto mem_error;
        }
        ctxt->nameTab = tmp;
        ctxt->nameMax *= 2;
    }
    if (ctxt->name == NULL) {
        ctxt->name = (xmlChar *)xmlStrdup(value);
    }
    ctxt->nameTab[ctxt->nameNr] = value;
    return (ctxt->nameNr++);
mem_error:
    xmlErrMemory(ctxt, NULL);
    return (-1);
}