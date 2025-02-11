AP_CORE_DECLARE(conn_rec *) ap_create_slave_connection(conn_rec *c)
{
    apr_pool_t *pool;
    conn_slave_rec *new;
    conn_rec *sc = apr_palloc(c->pool, sizeof(conn_rec));
    conn_rec *sc_copy = apr_palloc(c->pool, sizeof(conn_rec));

    apr_pool_create(&pool, c->pool);
    apr_pool_tag(pool, "slave_conn");
    memcpy(sc_copy, c, sizeof(conn_rec));
    sc_copy->slaves = NULL;
    sc_copy->master = c;
    sc_copy->input_filters = NULL;
    sc_copy->output_filters = NULL;
    sc_copy->pool = pool;

    new = apr_array_push(c->slaves);
    new->c = sc_copy;
    return sc_copy;
}