static void megasas\_frame\_set\_scsi\_status(MegasasState \*s,
unsigned long frame, uint8\_t v)
{
unsigned long header\_addr = frame + offsetof(struct mfi\_frame\_header, scsi\_status);
if (header\_addr + sizeof(v) <= s->max\_frame\_header\_size) {
PCIDevice \*pci = &s->parent\_obj;
stb\_pci\_dma(pci, header\_addr, v);
}
}