static void var_read_metadata(AVFormatContext *avctx, const char *tag, int size)
{
    char *value = var_read_string(avctx->pb, size);
    if (value) {
        if (strlen(tag) > 128) {
            av_log(avctx, AV_LOG_ERROR, "Invalid metadata tag length\n");
            return;
        }
        if (size > 1024) {
            av_log(avctx, AV_LOG_ERROR, "Invalid metadata value length\n");
            return;
        }
        char *safe_value = strdup(value);
        if (safe_value) {
            av_dict_set(&avctx->metadata, tag, safe_value, 0);
            free(safe_value);
        }
    }
}