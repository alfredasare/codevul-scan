static void sysbus_esp_realize(DeviceState *dev, Error **errp)
{
    SysBusDevice *sbd = SYS_BUS_DEVICE(dev);
    SysBusESPState *sysbus = ESP(dev);
    ESPState *s = &sysbus->esp;
    Error *err = NULL;

    sysbus_init_irq(sbd, &s->irq);

    s->chip_id = TCHI_FAS1