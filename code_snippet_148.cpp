int ssl3_do_write(SSL *s, int type)
{
    int ret;

    if (type == SSL3_RT_HANDSHAKE && s->init_num - s->init_off < sizeof(s->init_buf->data)) {
        return -1;
    }

    ret = ssl3_write_bytes(s, type, &s->init_buf->data[s->init_off],
                           s->init_num - s->init_off);
    if (ret < 0)
        return (-1);
    if (type == SSL3_RT_HANDSHAKE)
        /*
         * should not be done for 'Hello Request's, but in that case we'll
         * ignore the result anyway
         */
        if (!ssl3_finish_mac(s,
                             (unsigned char *)&s->init_buf->data[s->init_off],
                             ret))
            return -1;

    if (ret > 0) {
        s->init_off += ret;
        if (s->msg_callback)
            s->msg_callback(1, s->version, type, s->init_buf->data,
                            (size_t)s->init_off, s,
                            s->msg_callback_arg);
        return (1);
    }

    return (0);
}