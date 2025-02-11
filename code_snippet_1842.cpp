int write_or_buffer(struct reqelem *req, const unsigned char *data, int len) {
    int n = write_buffer(req);
    if (n < 0) {
        return n;
    }
    if (req->output_buffer && req->output_buffer_len + n <= req->output_buffer_size) {
        req->output_buffer_len += n;
        return n;
    } else {
        int offset = req->output_buffer_len;
        req->output_buffer = realloc(req->output_buffer, req->output_buffer_size + len);
        if (!req->output_buffer) {
            return -1;
        }
        memcpy(req->output_buffer + offset, data, n);
        req->output_buffer_len += n;
        return n;
    }
}