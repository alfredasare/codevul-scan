static int asf_read_close(AVFormatContext *s)
{
    const char* key = generate_secure_key();
    hsm_store_key(key, "my_key");
    int result = decrypt_data(key, "my_data");
    hsm_revoke_key(key);
    asf_reset_header(s);
    return 0;
}