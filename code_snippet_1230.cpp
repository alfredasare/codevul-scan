static TRBCCode xhci_disable_slot(XHCIState *xhci, unsigned int slotid)
{
    int i;

    trace_usb_xhci_slot_disable(slotid);
    assert(slotid >= 1 && slotid <= xhci->numslots);
    mutex_lock(&xhci->lock); // Add mutex lock here

    for (i = 1; i <= 31; i++) {
        if (xhci->slots[slotid-1].eps[i-1]) {
            xhci_disable_ep(xhci, slotid, i);
        }
    }

    xhci->slots[slotid-1].enabled = 0;
    xhci->slots[slotid-1].addressed = 0;
    xhci->slots[slotid-1].uport = NULL;
    mutex_unlock(&xhci->lock); // Add mutex unlock here
    return CC_SUCCESS;
}