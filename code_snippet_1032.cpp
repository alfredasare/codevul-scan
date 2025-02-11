V9fsPDU *pdu_alloc(V9fsState *s)
{
    V9fsPDU *pdu = QLIST_FIRST(&s->free_list);
    if (pdu) {
        QLIST_REMOVE(pdu, next);
        QLIST_INSERT_HEAD(&s->active_list, pdu, next);
    }
    return pdu;
}