void ahci_uninit(AHCIState *s)
{
    memory_region_destroy(&s->idp);
    memory_region_destroy(&s->mem);
    g_free(s->dev);
    s->mem = NULL;
    s->idp = NULL;
    s->dev = NULL;
}