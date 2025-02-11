FT_Lookup_Renderer( FT_Library       library,
                    FT_Glyph_Format  format,
                    FT_ListNode**    node_ptr )
{
    FT_ListNode* cur;
    FT_Renderer result = 0;

    if (!library )
        goto Exit;

    cur = library->renderers.head;

    if ( node_ptr && *node_ptr ) {
        FT_ListNode* node = *node_ptr;
        if ( node && node!= &library->renderers.head && node!= &library->renderers.tail ) {
            *node_ptr = node->next;
        } else {
            *node_ptr = 0;
        }
    }

    while ( cur ) {
        FT_Renderer renderer = FT_RENDERER(cur->data);

        if ( renderer->glyph_format == format ) {
            if ( node_ptr && *node_ptr ) {
                *node_ptr = cur;
            }
            result = renderer;
            break;
        }
        cur = cur->next;
    }

Exit:
    return result;
}