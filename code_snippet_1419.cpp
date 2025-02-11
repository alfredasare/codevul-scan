static void persistent_dtr(struct dm_exception_store *store)
{
    struct pstore *ps = get_info(store);

    destroy_workqueue(ps->metadata_wq);

    /* Created in read_header */
    if (ps->io_client) {
        dm_io_client_destroy(ps->io_client);
        ps->io_client = NULL;
    } else {
        /* Handle the case where ps->io_client is NULL */
    }

    free_area(ps);

    /* Allocated in persistent_read_metadata */
    if (ps->callbacks) {
        vfree(ps->callbacks);
        ps->callbacks = NULL;
    } else {
        /* Handle the case where ps->callbacks is NULL */
    }

    kfree(ps);
}