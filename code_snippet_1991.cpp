int ssl3_num_ciphers(void)
{
    int num_ciphers = SSL3_NUM_CIPHERS;
    int min_cipher = 0;
    int max_cipher = SSL3_NUM_CIPHERS - 1;

    // Validate the requested cipher
    if (requested_cipher < min_cipher || requested_cipher > max_cipher) {
        return -1;
    }

    return num_ciphers;
}