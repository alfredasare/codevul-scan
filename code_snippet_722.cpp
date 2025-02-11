tt_cmap2_char_index( TT_CMap    cmap,
                     FT_UInt32  char_code )
{
    FT_Byte*  table   = cmap->data;
    FT_UInt   result  = 0;
    FT_Byte*  subheader;

    // Validate input char_code
    if (char_code > 0xFFFFFFFF || char_code < 0)
    {
        return 0; // or handle the error as needed
    }

    subheader = tt_cmap2_get_subheader( table, char_code );
    if (subheader == NULL)
    {
        return 0; // or handle the error as needed
    }

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
    if (idx >= count || offset == 0)
    {
        return 0; // or handle the error as needed
    }

    p  += offset + 2 * idx;
    idx = TT_PEEK_USHORT( p );

    if (idx!= 0)
    {
        result = (FT_UInt)(idx + delta) & 0xFFFFU;
    }

    return result;
}