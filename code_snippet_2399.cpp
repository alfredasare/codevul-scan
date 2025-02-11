static unsigned short get_ushort(const unsigned char *data, size_t size)
{
    if (size < sizeof(unsigned short)) {
        return 0; // or some other error handling mechanism
    }

    unsigned short val = *(const unsigned short *)data;

#ifdef OPJ_BIG_ENDIAN
    val = ((val & 0xffU) << 8) | (val >> 8);
#endif
    return val;
}