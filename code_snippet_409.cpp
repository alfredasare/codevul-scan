static void free_event_gui_data_t(event_gui_data_t *evdata, void *unused)
{
    if (evdata && evdata->event_name)
    {
        free(evdata->event_name);
        free(evdata);
    }
    else
    {
        // Handle error or exception
        fprintf(stderr, "Error freeing event GUI data: %p\n", (void *)evdata);
    }
}