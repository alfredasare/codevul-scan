CatalogueAddFPE (CataloguePtr cat, FontPathElementPtr fpe)
{
    FontPathElementPtr *new;
    size_t new_size;

    if (cat->fpeCount > cat->fpeAlloc)
    {
        new_size = cat->fpeAlloc * 2;

        new = xzalloc(new_size * sizeof(FontPathElementPtr));

        if (new == NULL)
            return AllocError;

        memcpy(new, cat->fpeList, cat->fpeAlloc * sizeof(FontPathElementPtr));

        cat->fpeList = new;
        cat->fpeAlloc = new_size;
    }

    cat->fpeList[cat->fpeCount++] = fpe;

    return Successful;
}