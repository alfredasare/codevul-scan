TT_UInt32 tt_cmap2_char_index( TT_CMap    cmap,
                       FT_UInt32  char_code )
{
  FT_Byte*  table   = cmap->data;
  TT_UInt32 result  = 0;
  FT_Byte*  subheader;


  subheader = tt_cmap2_get_subheader( table, char_code );
  if ( subheader )
  {
    FT_Byte*  p   = subheader;
    FT_UInt   idx = (FT_UInt)(char_code & 0xFF);
    FT_UInt   start, count;
    FT_Int    delta;
    FT_UInt   offset;


    start  = TT_NEXT_USHORT( p );
    count  = TT_NEXT_USHORT( p );
    delta  = TT_NEXT_SHORT ( p );
    offset = TT_PEEK_USHORT( p );

    idx -= start;
    if ( idx < count && offset != 0 )
    {
      p  += offset + 2 * idx;
      idx = TT_PEEK_USHORT( p );

      if ( idx != 0 )
        result = (TT_UInt32)( idx + delta ) & 0xFFFFU;
    }
  }
  return result;
}