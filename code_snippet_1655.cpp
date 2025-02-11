static AHCICmdHdr *get_cmd_header(AHCIState *s, uint8_t port, uint8_t slot)
{
    if (port > (uint8_t)(sizeof(s->dev) / sizeof(s->dev[0])) || slot > (uint8_t)(sizeof(s->dev[port].lst) / sizeof(s->dev[port].lst[0]))
        return NULL;

    return s->dev[port].lst? &((AHCICmdHdr *)s->dev[port].lst)[slot] : NULL;
}