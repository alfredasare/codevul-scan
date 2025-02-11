struct fpm_worker_pool_s {
int max_children;
int current_children;
};

int fpm_children_create_initial(struct fpm_worker_pool_s *wp) {
if (wp->config->pm == PM_STYLE_ONDEMAND && wp->current_children < wp->max_children) {
wp->ondemand\_event = (struct fpm\_event\_s*)malloc(sizeof(struct fpm\_event\_s));

if (!wp->ondemand\_event) {
zlog(ZLOG\_ERROR, "[pool %s] unable to malloc the ondemand socket event", wp->config->name);
return 1;
}

memset(wp->ondemand\_event, 0, sizeof(struct fpm\_event\_s));
fpm\_event\_set(wp->ondemand\_event, wp->listening\_socket, FPM\_EV\_READ | FPM\_EV\_EDGE, fpm\_pctl\_on\_socket\_accept, wp);
wp->socket\_event\_set = 1;
fpm\_event\_add(wp->ondemand\_event, 0);

wp->current\_children++;

return 1;
}
return fpm\_children\_make(wp, 0 /* not in event loop yet */, 0, 1);
}