void readscreen(void)
{
    unsigned char buf[16];

    fread(buf, 1, 16, infile);
    global = buf[4] & 0x80;
    if (global) {
        globalbits = (buf[4] & 0x07) + 1;
        size_t bytesRead = fread(globalmap, 1, ((size_t)1) << globalbits, infile);
        if (bytesRead!= ((size_t)1) << globalbits) {
            // Handle error or invalid input
        }
    }
}