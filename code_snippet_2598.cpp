CatalogueAddFPE (CataloguePtr cat, FontPathElementPtr fpe)
{
    FontPathElementPtr *new;
    size_t new_alloc;

    if (cat->fpeCount + 1 >= cat->fpeAlloc)
    {
        new_alloc = cat->fpeAlloc == 0 ? 16 : cat->fpeAlloc * 2;
        new = reallocarray(cat->fpeList, new_alloc, sizeof(FontPathElementPtr));
        if (new == NULL)
            return AllocError;

        cat->fpeList = new;
        cat->fpeAlloc = new_alloc;
    }

    cat->fpeList[cat->fpeCount++] = fpe;

    return Successful;
}