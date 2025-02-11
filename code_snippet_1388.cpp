static void prep_output(h2_stream *stream) {
conn\_rec \*c = stream->session->c;
if (!stream->out\_buffer && c->input\_filter) {
stream->out\_buffer = apr\_brigade\_create(stream->pool, c->bucket\_alloc);
}
}