ieee8021q_tci_string(const uint16_t tci)
{
    static char buf[256];
    char temp[64];

    snprintf(temp, sizeof(temp), "vlan %u, p %u", tci & 0xfff, tci >> 13);
    if (tci & 0x1000) {
        strcat(temp, ", DEI");
    }
    snprintf(buf, sizeof(buf), "%s", temp);
    return buf;
}