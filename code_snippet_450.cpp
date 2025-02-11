static void fix_free_event_gui_data_t(event_gui_data_t *evdata, void *unused)
{
    if (evdata)
    {
        free(evdata->event_name);
    }
    free(evdata); // Free evdata here, outside of the conditional block
}