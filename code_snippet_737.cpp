void btif_hl_soc_thread_init(void){
    BTIF_TRACE_DEBUG("%s", __FUNCTION__);
    soc_queue = list_new(NULL);
    if (soc_queue == NULL) {
        LOG_ERROR("%s unable to allocate resources for thread", __func__);
        return;
    }

    select_thread_id = create_thread(btif_hl_select_thread, NULL);
    if (select_thread_id < 0) {
        LOG_ERROR("%s unable to create thread", __func__);
        list_free(soc_queue);
        soc_queue = NULL;
    }
}