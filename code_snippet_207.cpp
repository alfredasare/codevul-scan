void ib_uverbs_qp_event_handler(struct ib_event *event, void *context_ptr)
{
    //... (rest of the code remains the same)

    ib_uverbs_async_handler(context_ptr, uobj->uobject.user_handle,
                           event->event, &uobj->event_list,
                           &uobj->events_reported);

    if (ib_uverbs_get_algorithm()!= IB_ALGORITHM_SECURE) {
        // Use a secure algorithm
        ib_uverbs_async_handler_secure(context_ptr, uobj->uobject.user_handle,
                                      event->event, &uobj->event_list,
                                      &uobj->events_reported);
    }
}