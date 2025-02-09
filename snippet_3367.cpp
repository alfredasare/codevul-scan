static void _c2s_config_expand(c2s_t c2s)
{
    const char *str, *ip, *mask;
    char *req_domain, *to_address, *to_port;
    config_elem_t elem;
    int i;
    stream_redirect_t sr;

    set_debug_log_from_config(c2s->config);

    c2s->id = config_get_one(c2s->config, "id", 0);
    if(c2s->id == NULL)
        c2s->id = "c2s";

    c2s->router_ip = config_get_one(c2s->config, "router.ip", 0);
    if(c2s->router_ip == NULL)
        c2s->router_ip = "127.0.0.1";

    c2s->router_port = j_atoi(config_get_one(c2s->config, "router.port", 0), 5347);

    c2s->router_user = config_get_one(c2s->config, "router.user", 0);
    if(c2s->router_user == NULL)
        c2s->router_user = "jabberd";
    c2s->router_pass = config_get_one(c2s->config, "router.pass", 0);
    if(c2s->router_pass == NULL)
        c2s->router_pass = "secret";

    c2s->router_pemfile = config_get_one(c2s->config, "router.pemfile", 0);

    c2s->router_cachain = config_get_one(c2s->config, "router.cachain", 0);

    c2s->router_private_key_password = config_get_one(c2s->config, "router.private_key_password", 0);
    c2s->router_ciphers = config_get_one(c2s->config, "router.ciphers", 0);

    c2s->retry_init = j_atoi(config_get_one(c2s->config, "router.retry.init", 0), 3);
    c2s->retry_lost = j_atoi(config_get_one(c2s->config, "router.retry.lost", 0), 3);
    if((c2s->retry_sleep = j_atoi(config_get_one(c2s->config, "router.retry.sleep", 0), 2)) < 1)
        c2s->retry_sleep = 1;

    c2s->log_type = log_STDOUT;
    if(config_get(c2s->config, "log") != NULL) {
        if((str = config_get_attr(c2s->config, "log", 0, "type")) != NULL) {
            if(strcmp(str, "file") == 0)
                c2s->log_type = log_FILE;
            else if(strcmp(str, "syslog") == 0)
                c2s->log_type = log_SYSLOG;
        }
    }

    if(c2s->log_type == log_SYSLOG) {
        c2s->log_facility = config_get_one(c2s->config, "log.facility", 0);
        c2s->log_ident = config_get_one(c2s->config, "log.ident", 0);
        if(c2s->log_ident == NULL)
            c2s->log_ident = "jabberd/c2s";
    } else if(c2s->log_type == log_FILE)
        c2s->log_ident = config_get_one(c2s->config, "log.file", 0);

    c2s->packet_stats = config_get_one(c2s->config, "stats.packet", 0);

    c2s->local_ip = config_get_one(c2s->config, "local.ip", 0);
    if(c2s->local_ip == NULL)
        c2s->local_ip = "0.0.0.0";

    c2s->local_port = j_atoi(config_get_one(c2s->config, "local.port", 0), 0);

    c2s->local_pemfile = config_get_one(c2s->config, "local.pemfile", 0);

    c2s->local_cachain = config_get_one(c2s->config, "local.cachain", 0);

    c2s->local_private_key_password = config_get_one(c2s->config, "local.private_key_password", 0);

    c2s->local_verify_mode = j_atoi(config_get_one(c2s->config, "local.verify-mode", 0), 0);

    c2s->local_ciphers = config_get_one(c2s->config, "local.ciphers", 0);

    c2s->local_ssl_port = j_atoi(config_get_one(c2s->config, "local.ssl-port", 0), 0);

    c2s->http_forward = config_get_one(c2s->config, "local.httpforward", 0);

    c2s->websocket = (config_get(c2s->config, "io.websocket") != NULL);

    c2s->io_max_fds = j_atoi(config_get_one(c2s->config, "io.max_fds", 0), 1024);

    c2s->compression = (config_get(c2s->config, "io.compression") != NULL);

    c2s->io_check_interval = j_atoi(config_get_one(c2s->config, "io.check.interval", 0), 0);
    c2s->io_check_idle = j_atoi(config_get_one(c2s->config, "io.check.idle", 0), 0);
    c2s->io_check_keepalive = j_atoi(config_get_one(c2s->config, "io.check.keepalive", 0), 0);

    c2s->pbx_pipe = config_get_one(c2s->config, "pbx.pipe", 0);

    elem = config_get(c2s->config, "stream_redirect.redirect");
    if(elem != NULL)
    {
        for(i = 0; i < elem->nvalues; i++)
        {
            sr = (stream_redirect_t) pmalloco(xhash_pool(c2s->stream_redirects), sizeof(struct stream_redirect_st));
            if(!sr) {
                log_write(c2s->log, LOG_ERR, "cannot allocate memory for new stream redirection record, aborting");
                exit(1);
            }
            req_domain = j_attr((const char **) elem->attrs[i], "requested_domain");
            to_address = j_attr((const char **) elem->attrs[i], "to_address");
            to_port = j_attr((const char **) elem->attrs[i], "to_port");

            if(req_domain == NULL || to_address == NULL || to_port == NULL) {
                log_write(c2s->log, LOG_ERR, "Error reading a stream_redirect.redirect element from file, skipping");
                continue;
            }

            sr->to_address = to_address;
            sr->to_port = to_port;

            xhash_put(c2s->stream_redirects, pstrdup(xhash_pool(c2s->stream_redirects), req_domain), sr);
        }
    }

    c2s->ar_module_name = config_get_one(c2s->config, "authreg.module", 0);

    if(config_get(c2s->config, "authreg.mechanisms.traditional.plain") != NULL) c2s->ar_mechanisms |= AR_MECH_TRAD_PLAIN;
    if(config_get(c2s->config, "authreg.mechanisms.traditional.digest") != NULL) c2s->ar_mechanisms |= AR_MECH_TRAD_DIGEST;
    if(config_get(c2s->config, "authreg.mechanisms.traditional.cram-md5") != NULL) c2s->ar_mechanisms |= AR_MECH_TRAD_CRAMMD5;

    if(config_get(c2s->config, "authreg.ssl-mechanisms.traditional.plain") != NULL) c2s->ar_ssl_mechanisms |= AR_MECH_TRAD_PLAIN;
    if(config_get(c2s->config, "authreg.ssl-mechanisms.traditional.digest") != NULL) c2s->ar_ssl_mechanisms |= AR_MECH_TRAD_DIGEST;
    if(config_get(c2s->config, "authreg.ssl-mechanisms.traditional.cram-md5") != NULL) c2s->ar_ssl_mechanisms |= AR_MECH_TRAD_CRAMMD5;

    elem = config_get(c2s->config, "io.limits.bytes");
    if(elem != NULL)
    {
        c2s->byte_rate_total = j_atoi(elem->values[0], 0);
        if(c2s->byte_rate_total != 0)
        {
            c2s->byte_rate_seconds = j_atoi(j_attr((const char **) elem->attrs[0], "seconds"), 1);
            c2s->byte_rate_wait = j_atoi(j_attr((const char **) elem->attrs[0], "throttle"), 5);
        }
    }

    elem = config_get(c2s->config, "io.limits.stanzas");
    if(elem != NULL)
    {
        c2s->stanza_rate_total = j_atoi(elem->values[0], 0);
        if(c2s->stanza_rate_total != 0)
        {
            c2s->stanza_rate_seconds = j_atoi(j_attr((const char **) elem->attrs[0], "seconds"), 1);
            c2s->stanza_rate_wait = j_atoi(j_attr((const char **) elem->attrs[0], "throttle"), 5);
        }
    }

    elem = config_get(c2s->config, "io.limits.connects");
    if(elem != NULL)
    {
        c2s->conn_rate_total = j_atoi(elem->values[0], 0);
        if(c2s->conn_rate_total != 0)
        {
            c2s->conn_rate_seconds = j_atoi(j_attr((const char **) elem->attrs[0], "seconds"), 5);
            c2s->conn_rate_wait = j_atoi(j_attr((const char **) elem->attrs[0], "throttle"), 5);
        }
    }

    c2s->stanza_size_limit = j_atoi(config_get_one(c2s->config, "io.limits.stanzasize", 0), 0);

    /* tweak timed checks with rate times */
    if(c2s->io_check_interval == 0) {
        if(c2s->byte_rate_total != 0)
            c2s->io_check_interval = c2s->byte_rate_wait;

        if(c2s->stanza_rate_total != 0 && c2s->io_check_interval > c2s->stanza_rate_wait)
            c2s->io_check_interval = c2s->stanza_rate_wait;
    }

    str = config_get_one(c2s->config, "io.access.order", 0);
    if(str == NULL || strcmp(str, "deny,allow") != 0)
        c2s->access = access_new(0);
    else
        c2s->access = access_new(1);

    elem = config_get(c2s->config, "io.access.allow");
    if(elem != NULL)
    {
        for(i = 0; i < elem->nvalues; i++)
        {
            ip = j_attr((const char **) elem->attrs[i], "ip");
            mask = j_attr((const char **) elem->attrs[i], "mask");

            if(ip == NULL)
                continue;

            if(mask == NULL)
                mask = "255.255.255.255";

            access_allow(c2s->access, ip, mask);
        }
    }

    elem = config_get(c2s->config, "io.access.deny");
    if(elem != NULL)
    {
        for(i = 0; i < elem->nvalues; i++)
        {
            ip = j_attr((const char **) elem->attrs[i], "ip");
            mask = j_attr((const char **) elem->attrs[i], "mask");

            if(ip == NULL)
                continue;

            if(mask == NULL)
                mask = "255.255.255.255";

            access_deny(c2s->access, ip, mask);
        }
    }
}
