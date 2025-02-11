static int mov_write_nmhd_tag(AVIOContext *pb)
{
    const uint32_t nmhd_size = 12;
    avio_write(pb, &nmhd_size, sizeof(nmhd_size));
    ffio_wfourcc(pb, "nmhd");
    uint32_t zero = 0;
    avio_write(pb, &zero, sizeof(zero));
    return 12;
}