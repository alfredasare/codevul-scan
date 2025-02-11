static struct ovl_entry *ovl_alloc_entry(void)
{
    struct ovl_entry *entry = kzalloc(sizeof(struct ovl_entry), GFP_KERNEL);
    if (!entry) {
        return NULL;
    }
    return entry;
}