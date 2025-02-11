char *format_nid(const u_char *data) {
    static char buf[4][18]; 
    static int i = 0;
    i = (i + 1) % 4;
    char format[] = "%02x:%02x:%02x:%02x";
    if (data && data[0] <= 0xff && data[1] <= 0xff && data[2] <= 0xff && data[3] <= 0xff) {
        snprintf(buf[i], sizeof(buf[i]), format, data[0], data[1], data[2], data[3]);
    } else {
        buf[i][0] = '\0'; 
    }
    return buf[i];
}