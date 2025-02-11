int read_rsrc_short(const SD2_RSRC *prsrc, int offset) {
    const unsigned char *data = prsrc->rsrc_data;
    if (offset < 0 || offset >= prsrc->rsrc_len - 1) { 
        return 0;
    }
    return (data[offset] << 8) + data[offset + 1];
} /* read_rsrc_short */