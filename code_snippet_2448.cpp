read_bytes(FILE *fp, void *buf, size_t bytes_to_read, int fail_on_eof, char *errbuf)
{
    size_t amt_read;
    size_t buffer_size = sizeof(*buf); // Assume buf is a pointer to a buffer

    if (bytes_to_read > buffer_size) {
        pcap_fmt_errmsg_for_errno(errbuf, PCAP_ERRBUF_SIZE, EINVAL,
            "Invalid buffer size; cannot read %zu bytes into a buffer of size %zu",
            bytes_to_read, buffer_size);
        return (-1);
    }

    amt_read = fread(buf, 1, bytes_to_read, fp);
    ...
}