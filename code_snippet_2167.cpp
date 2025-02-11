static irqreturn_t host_irq(int irqnum, struct usb_hcd *hcd)
{
    struct ci13xxx *ci = get_ci13xxx_irqdata(irqnum);

    if (!ci || !ci->irq || !ci->hcd) {
        return IRQ_NONE;
    }

    return usb_hcd_irq(ci->irq, ci->hcd);
}