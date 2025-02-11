#include <stdint.h>

cff_parse_integer( FT_Byte*  start,
                   FT_Byte*  limit )
{
    FT_Byte*  p   = start;
    FT_Int    v   = *p++;
    FT_Long   val = 0;

    if ( v == 28 )
    {
        if ( p + 2 > limit )
            goto Bad;

        uint16_t tmp = (uint16_t)((uint16_t)p[0] << 8) | p[1];
        val = (FT_Long)tmp;
    }
    else if ( v == 29 )
    {
        if ( p + 4 > limit )
            goto Bad;

        uint32_t tmp = (uint32_t)((uint32_t)p[0] << 24) |
                          ((uint32_t)p[1] << 16) |
                          ((uint32_t)p[2] << 8) |
                          (uint32_t)p[3];
        val = (FT_Long)tmp;
    }
    else if ( v < 247 )
    {
        val = v - 139;
    }
    else if ( v < 251 )
    {
        if ( p + 1 > limit )
            goto Bad;

        uint8_t tmp = p[0];
        val = (v - 247) * 256 + tmp + 108;
    }
    else
    {
        if ( p + 1 > limit )
            goto Bad;

        uint8_t tmp = p[0];
        val = -(v - 251) * 256 - tmp - 108;
    }

Exit:
    return val;

Bad:
    val = 0;
    FT_TRACE4(( "!!!END OF DATA:!!!" ));
    goto Exit;
}