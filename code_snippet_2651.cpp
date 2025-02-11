static void bin_no_resources(RCore *r, int mode) {
        if (IS_MODE_JSON(mode)) {
                const char json_data[] = "[]";
                size_t json_len = sizeof(json_data) / sizeof(json_data[0]);
                if (r_cons_out_capacity(r->con) >= json_len) {
                        r_cons_write(r->con, json_data, json_len);
                } else {
                        // Handle error when buffer is too small
                }
        }
}