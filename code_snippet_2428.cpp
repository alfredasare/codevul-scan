int ssl3_send_hello_request(SSL *s)
{
    if (s->state == SSL3_ST_SW_HELLO_REQ_A)
    {
        ssl_set_handshake_header(s, SSL3_MT_HELLO_REQUEST, 0);
        s->state = SSL3_ST_SW_HELLO_REQ_B;
    }

    uint16_t buffer_size = s->buffer_size;
    if (buffer_size < SSL3_MAX_HELLO_REQUEST_SIZE)
    {
        memcpy(s->buffer, ..., buffer_size);
    }
    else
    {
        // Handle buffer overflow error
        //...
    }

    return ssl_do_write(s);
}