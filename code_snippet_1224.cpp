n;
s->init_off = 0;

return 1;
}

int tls_init_buf_size(SSL *s) {
return SSL_BUFFER_SIZE(s) - sizeof(s->init_num) - sizeof(s->init_off);
}