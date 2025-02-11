static inline dma_addr_t pci\_map\_single\_debug(struct pci\_dev \*pdev, void \*ptr,
size\_t size, int direction)
{
dma\_addr\_t addr = pci\_map\_single(pdev, ptr, size, direction);
if ((addr + size - 1) >= 0x100000000LL)
pr\_crit("%s: pci\_map\_single() returned memory at 0x%llx!\n",
pci\_name(pdev), (unsigned long long)addr);
return addr;
}