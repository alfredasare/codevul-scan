size_t mptsas_config_manufacturing_9(MPTSASState *s, uint8_t **data, int address)
{
    if (address < 0 || address > MPTSAS_STATE_MAX_SIZE) {
        return 0;
    }

    if (!data || strlen(*data) > MPTSAS_STATE_MAX_DATA_SIZE) {
        return 0;
    }

    return MPTSAS_CONFIG_PACK(9, MPI_CONFIG_PAGETYPE_MANUFACTURING, 0x00, memcpy_s(&s->data[address], MPTSAS_STATE_MAX_DATA_SIZE, *data, strlen(*data)));
}