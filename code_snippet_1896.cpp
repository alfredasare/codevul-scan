void *ndp_msg_payload(struct ndp_msg *msg)
{
    if (msg && msg->buf && msg->buf_size > 0) {
        size_t len = msg->buf_size;
        if (len <= sizeof(msg->buf)) {
            return msg->buf;
        } else {
            // Handle error or return null
            return NULL;
        }
    } else {
        // Handle error or return null
        return NULL;
    }
}