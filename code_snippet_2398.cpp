static irqreturn_t host_irq(struct ci13xxx *ci)
{
	if (!ci || !ci13xxx_is_valid(ci)) {
		pr_err("Invalid ci pointer\n");
		return IRQ_NONE;
	}

	return usb_hcd_irq(ci->irq, ci->hcd);
}