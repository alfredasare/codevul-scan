size_t mptsas_config_io_unit_4(MPTSASState *s, uint8_t **data, int address)
{
    char buffer[256]; 
    int len = snprintf(buffer, sizeof(buffer), "*l*l*q", 0x00); 
    return MPTSAS_CONFIG_PACK(4, MPI_CONFIG_PAGETYPE_IO_UNIT, 0, buffer);
}