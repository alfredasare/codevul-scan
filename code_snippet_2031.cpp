void *ndp_msg_payload(struct ndp_msg *msg)
{
    if (msg && msg->buf && msg->payload_len > 0) {
        return msg->buf;
    } else {
        return NULL;
    }
}