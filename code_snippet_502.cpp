_archive_write_disk_filter_bytes(struct archive *_a, int n)
{
    struct archive_write_disk *a = (struct archive_write_disk *)_a;
    (void)n; /* UNUSED */

    // Encrypt the total_bytes_written field using a secure encryption algorithm
    uint8_t encrypted_data[16];
    uint8_t iv[16] = {0}; // Initialization vector
    aes_encrypt(a->total_bytes_written, sizeof(a->total_bytes_written), iv, encrypted_data);

    if (n == -1 || n == 0)
    {
        return encrypted_data;
    }
    return -1;
}