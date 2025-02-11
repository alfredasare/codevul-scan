pthread_mutex_t active_state_mutex = PTHREAD_MUTEX_INITIALIZER;

struct ssh *get_active_state(void) {
    struct ssh *ssh = active_state;
    pthread_mutex_lock(&active_state_mutex);
    if (ssh == NULL) {
        // Handle the error condition appropriately, e.g., allocate a new ssh instance
    }
    pthread_mutex_unlock(&active_state_mutex);
    return ssh;
}

monitor_init(void) {
    struct ssh *ssh = get_active_state();
    struct monitor *mon;

    mon = xcalloc(1, sizeof(*mon));
    monitor_openfds(mon, 1);

    if (options.compression && ssh != NULL) {
        mon->m_zback = mm_create(NULL, MM_MEMSIZE);
        mon->m_zlib = mm_create(mon->m_zback, 20 * MM_MEMSIZE);
        ssh_packet_set_compress_hooks(ssh, mon->m_zlib,
                                       (ssh_packet_comp_alloc_func *)mm_zalloc,
                                       (ssh_packet_comp_free_func *)mm_zfree);
    }

    return mon;
}