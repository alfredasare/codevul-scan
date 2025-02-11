void ahci_uninit(AHCIState *s)
{
    if (s->mem.data) {
        memory_region_destroy(&s->mem);
    }
    if (s->idp.data) {
        memory_region_destroy(&s->idp);
    }
    g_free(s->dev);

    // Initialize pointers to NULL after destroying regions
    s->mem.data = NULL;
    s->idp.data = NULL;
}