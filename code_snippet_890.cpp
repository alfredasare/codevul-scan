static void put_amf_string(AVIOContext *pb, const char *str, size_t max_buffer_size)
{
    size_t len = strlen(str);
    if (len > max_buffer_size) {
        return;
    }
    avio_wb16(pb, len);
    avio_write(pb, str, len);
}