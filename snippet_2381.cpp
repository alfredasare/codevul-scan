XRecordFreeData(XRecordInterceptData *data)
{
    /* we can do this cast because that is what we really allocated */
    struct intercept_queue *iq = (struct intercept_queue *)data;
    struct reply_buffer *rbp = NULL;
    struct mem_cache_str *cache = iq->cache;

    /*
     * figure out what reply_buffer this points at
     * and decrement its ref_count.
     */
    if (data->data) {

	for (rbp = cache->reply_buffers; rbp; rbp = rbp->next) {
	    if (data->data >= rbp->buf
		&& data->data < rbp->buf + rbp->nbytes)
	    {
		assert(rbp->ref_count > 0);
		rbp->ref_count--;
		break;
	    }
	}
	/* it's an error if we didn't find something to free */
	assert(rbp);
    }
    /*
     * If the display is still open, put this back on the free queue.
     *
     * Otherwise the display is closed and we won't reuse this, so free it.
     * See if we can free the reply buffer, too.
     * If we can, see if this is the last reply buffer and if so
     * free the list of reply buffers.
     */
    if (cache->display_closed == False) {
	iq->next = cache->inter_data;
	cache->inter_data = iq;
    } else {
	if (rbp && rbp->ref_count == 0) {
	    struct reply_buffer *rbp2, **rbp_next_p;

	    /* Have to search the list again to find the prev element.
	       This is not the common case, so don't slow down the code
	       above by doing it then. */
	    for (rbp_next_p = &cache->reply_buffers; *rbp_next_p; ) {
		rbp2 = *rbp_next_p;
		if (rbp == rbp2) {
		    *rbp_next_p = rbp2->next;
		    break;
		} else {
		    rbp_next_p = &rbp2->next;
		}
	    }
	    XFree(rbp->buf);
	    XFree(rbp);
	}

	XFree(iq);
	cache->inter_data_count--;

	if (cache->reply_buffers == NULL  &&  cache->inter_data_count == 0) {
	    XFree(cache); /* all finished */
	}
    }
}
