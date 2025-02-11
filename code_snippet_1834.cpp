static void amd_gpio_irq_mask(struct irq_data *d)
{
	unsigned long flags;
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct amd_gpio *gpio_dev = gpiochip_get_data(gc);

	spin_lock_irqsave(&gpio_dev->lock, flags);
	readl_relaxed(gpio_dev->base + (d->hwirq)*4);
	writel_relaxed(readl(gpio_dev->base + (d->hwirq)*4) & ~BIT(INTERRUPT_MASK_OFF),
	               gpio_dev->base + (d->hwirq)*4);
	spin_unlock_irqrestore(&gpio_dev->lock, flags);
}