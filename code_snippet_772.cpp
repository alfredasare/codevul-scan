static void put_amf_string(AVIOContext *pb, const char *str)
{
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s", str);
    avio_wb16(pb, strlen(buffer));
    avio_write(pb, buffer, strlen(buffer));
}