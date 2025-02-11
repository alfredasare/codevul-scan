static unsigned short get_ushort(const unsigned char *data)
{
    unsigned short val = 0;
    for (int i = 0; i < sizeof(unsigned short); i++)
    {
        if (data + i < (const unsigned char *)NULL || data + i >= (const unsigned char *)(NULL + sizeof(unsigned short)))
        {
            return 0;
        }
        val |= ((unsigned short)data[i]) << (i * 8);
    }

#ifdef OPJ_BIG_ENDIAN
    val = __builtin_bswap16(val);
#endif
    return val;
}