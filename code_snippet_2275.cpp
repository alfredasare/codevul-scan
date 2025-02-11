flash_eerd_read(E1000State *s, int x)
{
    size_t index, r = s->mac_reg[EERD] & ~E1000_EEPROM_RW_REG_START;

    if ((s->mac_reg[EERD] & E1000_EEPROM_RW_REG_START) == 0)
        return (s->mac_reg[EERD]);

    if ((index = r >> E1000_EEPROM_RW_ADDR_SHIFT) > EEPROM_CHECKSUM_REG) {
        index = clamp(index, 0, EEPROM_CHECKSUM_REG - 1);
        return (E1000_EEPROM_RW_REG_DONE | r);
    }

    return ((s->eeprom_data[index] << E1000_EEPROM_RW_REG_DATA) |
           E1000_EEPROM_RW_REG_DONE | r);
}