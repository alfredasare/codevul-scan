pdf_set_usecmap(fz_context *ctx, pdf_cmap *cmap, pdf_cmap *usecmap)
{
    int i;
    pdf_cmap *new_cmap = pdf_keep_cmap(ctx, usecmap);

    if (cmap->codespace_len == 0)
    {
        cmap->codespace_len = new_cmap->codespace_len;
        for (i = 0; i < new_cmap->codespace_len; i++)
            cmap->codespace[i] = new_cmap->codespace[i];
    }

    cmap->usecmap = new_cmap;
    pdf_drop_cmap(ctx, new_cmap);
}