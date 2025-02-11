static int _c2s_router_connect(c2s_t c2s) {
    log_write(c2s->log, LOG_NOTICE, "attempting connection to router at %s, port=%d", c2s->router_ip, c2s->router_port);

    int fd = mio_connect(c2s->mio, c2s->router_port, c2s->router_ip, NULL, c2s_router_mio_callback, (void *) c2s);
    if(fd == NULL) {
        if(errno == ECONNREFUSED)
            c2s_lost_router = 1;
        log_write(c2s->log, LOG_NOTICE, "connection attempt to router failed: %s (%d)", MIO_STRERROR(MIO_ERROR), MIO_ERROR);
        return 1;
    }

    if (fd >= 0) {
        c2s->router = sx_new(c2s->sx_env, &fd, c2s_router_sx_callback, (void *) c2s);
    } else {
        log_write(c2s->log, LOG_NOTICE, "Invalid file descriptor: %d", fd);
        return 1;
    }

    sx_client_init(c2s->router, 0, NULL, NULL, NULL, "1.0");

    return 0;
}