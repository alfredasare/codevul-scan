cobuf = g_new0(guint8, phdr->caplen);
        if (cobuf == NULL) {
            *err = WTAP_ERR_NO_MEMORY;
            return FALSE;
        }

        pkt_len = parse_cosine_hex_dump(wth->random_fh, phdr, phdr->caplen,
                                        cobuf, err, err_info);
        if (pkt_len == -1) {
            g_free(cobuf);
            return FALSE;
        }

        buf_set_used_bytes(buf, pkt_len);
        memcpy(buf->data, cobuf, pkt_len);
        g_free(cobuf);

        return TRUE;