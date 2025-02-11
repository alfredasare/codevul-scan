int ssl3_peek(SSL *s, void *buf, size_t buf_len)
{
    // Check if len is within the bounds of the buffer
    if (buf_len < SSL3_RT_MAX_PLAINTEXT_LEN) {
        // Handle error condition appropriately, e.g., return an error code
        return -1;
    }

    return ssl3_read_internal(s, buf, SSL3_RT_MAX_PLAINTEXT_LEN, SSL3_PEEK);
}