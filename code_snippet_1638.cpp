tt_cmap6_get_info( TT_CMap       cmap,
                     TT_CMapInfo  *cmap_info )
{
    FT_Byte*  p = cmap->data + 4;

    if (p < cmap->data || p >= cmap->data + cmap->size) {
        return FT_Err_Invalid_Argument;
    }

    cmap_info->format   = 6;
    cmap_info->language = (FT_ULong)TT_PEEK_USHORT( p );

    return FT_Err_Ok;
}