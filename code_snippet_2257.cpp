void ff_amf_write_number(uint8_t **dst, double val)
{
    if (isnan(val) || isinf(val)) {
        bytestream_put_byte(dst, AMF_DATA_TYPE_NULL);
        return;
    }

    if (val > 9.999999e15 || val < -9.999999e15) {
        bytestream_put_byte(dst, AMF_DATA_TYPE_NULL);
        return;
    }

    long long int64 = llround(val);
    bytestream_put_byte(dst, AMF_DATA_TYPE_NUMBER);
    bytestream_put_be64(dst, int64);
}