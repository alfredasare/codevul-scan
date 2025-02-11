static BOOL update_begin_paint(rdpContext* context)
{
    wStream* s;
    rdpUpdate* update = context->update;

    if (update->us)
        update->EndPaint(context);

    s = fastpath_update_pdu_init_new(context->rdp->fastpath);

    if (!s)
        return FALSE;

    // Ensure the buffer has enough space
    if (Stream_GetCapacity(s) - Stream_GetPosition(s) < 2)
    {
        // Handle error: not enough space in the buffer
        Stream_Free(s, FALSE);
        return FALSE;
    }

    // Perform bounds-checked writing
    Stream_Write_UINT1