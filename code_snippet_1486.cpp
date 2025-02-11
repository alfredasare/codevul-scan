UNCURL_EXPORT int32_t uncurl_ws_close(struct uncurl_conn *ucc, uint16_t status_code)
{
    uint16_t status_code_be = htons(status_code);
    char buffer[4]; // assume uint16_t is 2 bytes

    // sanitize the format string using snprintf
    snprintf(buffer, sizeof(buffer), "%hu", status_code_be);

    return uncurl_ws_write(ucc, buffer, strlen(buffer), UNCURL_WSOP_CLOSE);
}