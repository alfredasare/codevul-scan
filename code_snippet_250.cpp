static int mov_write_dref_tag(AVIOContext *pb)
{
    int maxSize = 40; // Assuming 40 bytes for the entire buffer
    char buffer[maxSize]; 

    if (avio_wb32(pb, buffer, maxSize) < 0) {
        return -1;
    }

    avio_wb32(pb, 28); /* size */
    ffio_wfourcc(pb, "dref");
    avio_wb32(pb, 0); /* version & flags */
    avio_wb32(pb, 1); /* entry count */

    avio_wb32(pb, 0xc); /* size */
    ffio_wfourcc(pb, "url ");
    avio_wb32(pb, 1); /* version & flags */

    return 28;
}