static int server_hello(SSL *s)
{
    unsigned char *p, *d;
    int n, hit;

    p = (unsigned char *)s->init_buf->data;
    if (s->state == SSL2_ST_SEND_SERVER_HELLO_A) {
        d = p + 11;
        *(p++) = SSL2_MT_SERVER_HELLO; /* type */
        hit = s->hit;
        *(p++) = (unsigned char)hit;
# if 1
        if (!hit) {
            if (s->session->sess_cert != NULL)
                /*
                 * This can't really happen because get_client_hello has
                 * called ssl_get_new_session, which does not set sess_cert.
                 */
                ssl_sess_cert_free(s->session->sess_cert);
            s->session->sess_cert = ssl_sess_cert_new();
            if (s->session->sess_cert == NULL) {
                SSLerr(SSL_F_SERVER_HELLO, ERR_R_MALLOC_FAILURE);
                return (-1);
            }
        }
        /*
         * If 'hit' is set, then s->sess_cert may be non-NULL or NULL,
         * depending on whether it survived in the internal cache or was
         * retrieved from an external cache. If it is NULL, we cannot put any
         * useful data in it anyway, so we don't touch it.
         */

# else                          /* That's what used to be done when cert_st
                                 * and sess_cert_st were * the same. */
        if (!hit) {             /* else add cert to session */
            CRYPTO_add(&s->cert->references, 1, CRYPTO_LOCK_SSL_CERT);
            if (s->session->sess_cert != NULL)
                ssl_cert_free(s->session->sess_cert);
            s->session->sess_cert = s->cert;
        } else {                /* We have a session id-cache hit, if the *
                                 * session-id has no certificate listed
                                 * against * the 'cert' structure, grab the
                                 * 'old' one * listed against the SSL
                                 * connection */
            if (s->session->sess_cert == NULL) {
                CRYPTO_add(&s->cert->references, 1, CRYPTO_LOCK_SSL_CERT);
                s->session->sess_cert = s->cert;
            }
        }
# endif

        if (s->cert == NULL) {
            ssl2_return_error(s, SSL2_PE_NO_CERTIFICATE);
            SSLerr(SSL_F_SERVER_HELLO, SSL_R_NO_CERTIFICATE_SPECIFIED);
            return (-1);
        }

        if (hit) {
            *(p++) = 0;         /* no certificate type */
            s2n(s->version, p); /* version */
            s2n(0, p);          /* cert len */
            s2n(0, p);          /* ciphers len */
        } else {
            /* EAY EAY */
            /* put certificate type */
            *(p++) = SSL2_CT_X509_CERTIFICATE;
            s2n(s->version, p); /* version */
            n = i2d_X509(s->cert->pkeys[SSL_PKEY_RSA_ENC].x509, NULL);
            s2n(n, p);          /* certificate length */
            i2d_X509(s->cert->pkeys[SSL_PKEY_RSA_ENC].x509, &d);
            n = 0;

            /*
             * lets send out the ciphers we like in the prefered order
             */
            n = ssl_cipher_list_to_bytes(s, s->session->ciphers, d, 0);
            d += n;
            s2n(n, p);          /* add cipher length */
        }

        /* make and send conn_id */
        s2n(SSL2_CONNECTION_ID_LENGTH, p); /* add conn_id length */
        s->s2->conn_id_length = SSL2_CONNECTION_ID_LENGTH;
        if (RAND_pseudo_bytes(s->s2->conn_id, (int)s->s2->conn_id_length) <=
            0)
            return -1;
        memcpy(d, s->s2->conn_id, SSL2_CONNECTION_ID_LENGTH);
        d += SSL2_CONNECTION_ID_LENGTH;

        s->state = SSL2_ST_SEND_SERVER_HELLO_B;
        s->init_num = d - (unsigned char *)s->init_buf->data;
        s->init_off = 0;
    }
    /* SSL2_ST_SEND_SERVER_HELLO_B */
    /*
     * If we are using TCP/IP, the performance is bad if we do 2 writes
     * without a read between them.  This occurs when Session-id reuse is
     * used, so I will put in a buffering module
     */
    if (s->hit) {
        if (!ssl_init_wbio_buffer(s, 1))
            return (-1);
    }

    return (ssl2_do_write(s));
}
