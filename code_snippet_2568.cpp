static void var_read_metadata(AVFormatContext *avctx, const char *tag, int size)
{
    uint8_t buffer[1024]; // Increase the buffer size if necessary
    size_t bytes_read = av_get_bytes_as_fast(avctx->pb, buffer, sizeof(buffer), &size);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Ensure null-termination
        av_dict_set(&avctx->metadata, tag, (char *)buffer, AV_DICT_DONT_STRDUP_VAL);
    }
}