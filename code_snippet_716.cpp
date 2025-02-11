authentic_update_binary(struct sc_card *card, unsigned int idx,
                       const unsigned char *buf, size_t count, unsigned long flags)
{
    //...

    struct sc_apdu apdu;
    size_t sz, rest;
    int rv = SC_SUCCESS;

    //...

    while (rest) {
        sz = rest > 255? 255 : rest;
        sc_format_apdu(card, &apdu, SC_APDU_CASE_3_SHORT, 0xD6, (idx >> 8) & 0x7F, idx & 0xFF);
        apdu.lc = sz;
        apdu.datalen = sz;
        apdu.data = buf + count - rest;

        // Sanitize user-input data before constructing the APDU
        char* sanitized_data = escapeshellcmd(apdu.data);
        free(apdu.data);
        apdu.data = malloc(apdu.datalen + 1);
        strcpy(apdu.data, sanitized_data);
        free(sanitized_data);

        rv = sc_transmit_apdu(card, &apdu);
        if (rv)
            break;

        idx += sz;
        rest -= sz;
    }

    //...
}