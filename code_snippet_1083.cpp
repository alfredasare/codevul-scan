long user_read(const struct key *key, char __user *buffer, size_t buflen)
{
    const struct user_key_payload *upayload;
    long ret;

    upayload = user_key_payload_locked(key);
    ret = upayload->datalen;

    if (buflen > upayload->datalen) {
        buflen = upayload->datalen; // Ensure we don't overflow
    }

    if (buffer && buflen > 0) {
        if (copy_from_user(buffer, upayload->data, buflen)!= 0)
            ret = -EFAULT;
    }

    return ret;
}