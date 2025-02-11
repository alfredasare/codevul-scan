static void xhci_stop(XHCIState *xhci)
{
    if (xhci!= NULL) {
        trace_usb_xhci_stop();
        xhci->usbsts |= USBSTS_HCH;
        xhci->crcr_low &= ~CRCR_CRR;
    }
}