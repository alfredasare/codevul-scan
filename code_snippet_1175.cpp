xsltTestCompMatchList(xsltTransformContextPtr ctxt, xmlNodePtr node,
		       xsltCompMatchPtr comp) {
    int ret;

    if ((ctxt == NULL) || (node == NULL) || (comp == NULL)) {
        assert(ctxt!= NULL && node!= NULL && comp!= NULL);
        return -1; // or throw an exception
    }

    while (comp!= NULL) {
        if (comp->next == NULL) {
            // bounds checking for the loop
            break;
        }
        ret = xsltTestCompMatch(ctxt, comp, node, NULL, NULL);
        if (ret == 1)
            return 1;
        comp = comp->next;
    }
    return 0;
}