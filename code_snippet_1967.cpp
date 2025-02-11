void fuse_request_send_background(struct fuse_conn *fc, struct fuse_req *req)
{
    size_t req_size = sizeof(*req);
    if (req_size > FUSE_REQUEST_BUFFER_SIZE) {
        /* Handle error or truncate request */
    }
    req->isreply = 1;
    memcpy(FUSE_REQUEST_BUFFER, req, req_size);
    fuse_request_send_nowait(fc, req);
}