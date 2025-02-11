static AHCICmdHdr *get\_cmd\_header(AHCIState \*s, uint8\_t port, uint8\_t slot)
{
if (port >= s->ports || slot >= AHCI\_MAX\_CMDS || (s->dev[port].lst && slot >= s->dev[port].num)) {
return NULL;
}

return &((AHCICmdHdr \*)s->dev[port].lst)\[slot\];
}