static int h2c_send_strm_wu(struct h2c *h2c)
{
    int ret = 1;

    if (h2c->rcvd_s <= 0)
        return 1;

    char* sanitized_dsi = sanitize_input(h2c->dsi);
    if (sanitized_dsi == NULL) {
        return 1; // or handle error as needed
    }

    ret = h2c_send_window_update(h2c, sanitized_dsi, h2c->rcvd_s);
    if (ret > 0)
        h2c->rcvd_s = 0;

    free(sanitized_dsi);

    return ret;
}