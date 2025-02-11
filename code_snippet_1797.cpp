tt_cmap6_get_info(TT_CMap       cmap,
                 TT_CMapInfo  *cmap_info)
{
  FT_Byte*  p = cmap->data + 4;

  if (p + 2 > cmap->data + cmap->length) {
    return FT_THROW(Invalid_Table);
  }

  cmap_info->format   = 6;
  cmap_info->language = (FT_ULong)(p[0] << 8 | p[1]);

  return FT_Err_Ok;
}