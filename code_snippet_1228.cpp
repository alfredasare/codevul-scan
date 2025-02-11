static void prep_output(h2_stream *stream) {
    if (!stream ||!stream->session) {
        return;
    }

    conn_rec *c = stream->session->c;
    if (!stream->out_buffer) {
        stream->out_buffer = apr_brigade_create(stream->pool, c->bucket_alloc);
    }
}