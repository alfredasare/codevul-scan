static BOOL update_begin_paint(rdpContext* context)
{
    wStream* s;
    rdpUpdate* update = context->update;
    const char* path = "/path/to/absolute/folder"; // Ensure path is absolute

    if (update->us)
        update->EndPaint(context);

    s = fastpath_update_pdu_init_new(path); // Use absolute path

    if (!s)
        return FALSE;

    Stream_SealLength(s);
    Stream_Seek(s, 2); /* numberOrders (2 bytes) */

    // Sanitize input data
    size_t len = strlen(update->combineUpdates);
    char sanitized[len + 1];
    strncpy(sanitized, update->combineUpdates, len);
    sanitized[len] = '\0';

    update->combineUpdates = sanitized;
    update->numberOrders = 0;
    update->us = s;
    return TRUE;
}