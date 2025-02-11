static void xhci_stop(XHCIState *xhci)
{
    // Validate the input parameter before proceeding
    if (!xhci) {
        pr_err("Invalid input! xhci pointer is NULL.\n");
        return;
    }

    trace_usb_xhci_stop();
    xhci->usbsts |= USBSTS_HCH;
    xhci->crcr_low &= ~CRCR_CRR;
}