V9fsPDU *pdu_alloc(V9fsState *s)
{
    V9fsPDU *pdu = pdu_allocate(s);
    if (pdu!= NULL) {
        QLIST_INSERT_HEAD(&s->active_list, pdu, next);
    }
    return pdu;
}

V9fsPDU *pdu_allocate(V9fsState *s)
{
    V9fsPDU *pdu = QLIST_FIRST(&s->free_list);
    if (pdu!= NULL) {
        QLIST_REMOVE(pdu, next);
    }
    return pdu;
}