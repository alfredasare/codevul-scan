static void acpi\_pcihp\_update\_hotplug\_bus(AcpiPciHpState \*s, int bsel)
{
buschild \*kid, \*next;
PCIBus \*bus = acpi\_pcihp\_find\_hotplug\_bus(s, bsel);

/* Execute any pending removes during reset */
while (s->acpi\_pcihp\_pci\_status[bsel].down) {
acpi\_pcihp\_eject\_slot(s, bsel, s->acpi\_pcihp\_pci\_status[bsel].down);
}

size\_t num\_slots = sizeof(s->acpi\_pcihp\_pci\_status[bsel].hotplug\_enable) \* 8;
s->acpi\_pcihp\_pci\_status[bsel].hotplug\_enable = (1U << num\_slots) - 1;

if (!bus) {
return;
}
QTAILQ\_FOREACH\_SAFE(kid, &bus->qbus.children, sibling, next) {
DeviceState \*qdev = kid->child;
PCIDevice \*pdev = PCI\_DEVICE(qdev);
int slot = PCI\_SLOT(pdev->devfn);

if (acpi\_pcihp\_pc\_no\_hotplug(s, pdev)) {
s->acpi\_pcihp\_pci\_status[bsel].hotplug\_enable &= ~(1U << slot);
}
}
}