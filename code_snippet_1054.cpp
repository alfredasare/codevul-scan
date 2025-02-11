int fpm_children_create_initial(struct fpm_worker_pool_s *wp) {
    if (wp->config->pm == PM_STYLE_ONDEMAND) {
        void* ondemand_event = malloc(sizeof(struct fpm_event_s));
        if (!ondemand_event) {
            free(ondemand_event);
            zlog(ZLOG_ERROR, "[pool %s] unable to malloc the ondemand socket event", wp->config->name);
            return 1;
        }

        memset(ondemand_event, 0, sizeof(struct fpm_event_s));
        fpm_event_set((struct fpm_event_s*)ondemand_event, wp->listening_socket, FPM_EV_READ | FPM_EV_EDGE, fpm_pctl_on_socket_accept, wp);
        wp->socket_event_set = 1;
        fpm_event_add((struct fpm_event_s*)ondemand_event, 0);

        return 1;
    }
    return fpm_children_make(wp, 0 /* not in event loop yet */, 0, 1);
}