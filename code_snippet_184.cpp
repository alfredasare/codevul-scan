void xs_init_match(struct xtables_match *match)
{
    if (match->udata_size!= 0) {
        match->udata = NULL;
        if (match->udata_size > MAX_UDATA_SIZE) {
            xtables_error(RESOURCE_PROBLEM, "udata size exceeds limit");
            return;
        }
        match->udata = strdup(match->init_data);
        if (match->udata == NULL) {
            xtables_error(RESOURCE_PROBLEM, "malloc");
        }
    }
    if (match->init!= NULL)
        match->init(match->m);
}