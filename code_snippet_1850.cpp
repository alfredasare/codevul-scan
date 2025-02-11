tt_cmap14_init( TT_CMap14  cmap,
                 FT_Byte*   table )
{
    cmap->cmap.data = table;

    if (table && table + 6 < cmap->cmap.data + cmap->cmap.size) {
        cmap->num_selectors = FT_PEEK_ULONG(table);
        cmap->max_results = 0;
        cmap->results = NULL;
    } else {
        // Handle buffer overread or invalid input
        // For example, return an error or set a flag to indicate an issue
    }

    return FT_Err_Ok;
}