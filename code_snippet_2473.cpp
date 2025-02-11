void ff_amf_write_number(uint8_t **dst, double val)
{
    if (val <= INT64_MIN || val >= INT64_MAX) {
        // Handle error case, e.g. return an error code
    } else {
        bytestream_put_byte(dst, AMF_DATA_TYPE_NUMBER);
        bytestream_put_be64(dst, av_double2int(val));
    }
}