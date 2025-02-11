static void amd_gpio_irq_mask(struct irq_data *d)
{
    u32 pin_reg;
    unsigned long flags;
    struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
    struct amd_gpio *gpio_dev = gpiochip_get_data(gc);

    spin_lock_irqsave(&gpio_dev->lock, flags);

    if (!capable(CAP_SYS_RAWIO)) {
        printk(KERN_ERR "Permission denied: cannot mask IRQ\n");
        spin_unlock_irqrestore(&gpio_dev->lock, flags);
        return;
    }

    pin_reg = readl(gpio_dev->base + (d->hwirq)*4);
    pin_reg &= ~BIT(INTERRUPT_MASK_OFF);
    writel(pin_reg, gpio_dev->base + (d->hwirq)*4);

    spin_unlock_irqrestore(&gpio_dev->lock, flags);
}