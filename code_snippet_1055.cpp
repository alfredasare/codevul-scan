readscreen(void)
{
    unsigned char buf[7];
    size_t bytes_read = fread(buf, 1, sizeof(buf), infile);
    if (bytes_read < sizeof(buf)) {
        global = (bytes_read > 3) ? (buf[4] & 0x80) : 0;
        if (global) {
            globalbits = (bytes_read > 4) ? ((buf[4] & 0x07) + 1) : 0;
            if (globalbits && bytes_read > 5) {
                fread(globalmap, 3, ((size_t)1) << globalbits, infile);
            }
        }
    }
}