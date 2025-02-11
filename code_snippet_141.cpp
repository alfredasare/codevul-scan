static int report(struct fsck_options *options, struct object *object,
                 enum fsck_msg_id id, const char *fmt,...)
{
    va_list ap;
    struct strbuf sb = STRBUF_INIT;
    int msg_type = fsck_msg_type(id, options), result;

    if (msg_type == FSCK_IGNORE)
        return 0;

    if (options->skiplist && object &&
            oid_array_lookup(options->skiplist, &object->oid) >= 0)
        return 0;

    if (msg_type == FSCK_FATAL)
        msg_type = FSCK_ERROR;
    else if (msg_type == FSCK_INFO)
        msg_type = FSCK_WARN;

    va_start(ap, fmt);
    char buffer[1024]; // fixed-size buffer
    vsnprintf(buffer, sizeof(buffer), fmt, ap);
    va_end(ap);

    append_msg_id(&sb, msg_id_info[id].id_string);
    strbuf_addf(&sb, buffer);
    result = options->error_func(options, object, msg_type, sb.buf);
    strbuf_release(&sb);

    return result;
}