int xsltTestCompMatchList(xsltTransformContextPtr ctxt, xmlNodePtr node, xsltCompMatchPtr comp) {
    int ret;

    if ((ctxt == NULL) || (node == NULL))
        return(-1);
    while (comp != NULL) {
        ret = xsltTestCompMatch(ctxt, comp, node, NULL, NULL);
        if (ret > 0) // Check if ret is non-zero, indicating a match
            return(1);
        comp = comp->next;
    }
    return(0);
}