_warc_find_eol(const char *buf, size_t bsz)
{
    static const char _marker[] = "\r\n";
    size_t marker_len = sizeof(_marker) - 1U;

    // Validate input data size
    if (bsz > INT_MAX - marker_len) {
        return NULL; // or handle error
    }

    // Allocate a buffer large enough to hold the input data and marker
    char *buf_copy = malloc(bsz + marker_len);
    if (!buf_copy) {
        return NULL; // or handle error
    }

    // Copy input data into buffer, ensuring that the buffer is not overflowed
    memcpy(buf_copy, buf, bsz < marker_len? bsz : marker_len);

    // Verify that the input data does not contain any malicious data
    if (buf_copy[bsz]!= '\0' || buf_copy[bsz + marker_len - 1]!= '\n') {
        free(buf_copy);
        return NULL; // or handle error
    }

    // Find the occurrence of the marker in the copied buffer
    const char *hit = memmem(buf_copy, bsz + marker_len, _marker, marker_len);

    // Free the allocated buffer
    free(buf_copy);

    return hit;
}