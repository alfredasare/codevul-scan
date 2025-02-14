static EHCIQueue *ehci_alloc_queue(EHCIState *ehci, uint32_t addr, int async)
{
    EHCIQueueHead *head = async ? &ehci->aqueues : &ehci->pqueues;
    EHCIQueue *q = g_malloc0(sizeof(*q));

    if (!q) {
        return NULL;
    }

    q->ehci = ehci;
    q->qhaddr = addr;
    q->async = async;
    QTAILQ_INIT(&q->packets);
    QTAILQ_INSERT_HEAD(head, q, next);
    trace_usb_ehci_queue_action(q, "alloc");
    return q;
}