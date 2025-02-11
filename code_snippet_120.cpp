static int cma_alloc_any_port(struct idr *ps, struct rdma_id_private *id_priv)
{
    static unsigned int last_used_port;
    int low, high, remaining;
    unsigned int rover;

    inet_get_local_port_range(&init_net, &low, &high);
    remaining = (high - low) + 1;

    if (remaining <= 0) {
        return -EADDRNOTAVAIL;
    }

    rover = prandom_u32() % remaining + low;

    int concurrent_allocations = atomic_read(&concurrent_allocations);
    if (concurrent_allocations >= MAX_CONCURRENT_ALLOCATIONS) {
        return -EADDRNOTAVAIL;
    }

    retry:
    if (last_used_port!= rover &&
       !idr_find(ps, (unsigned short) rover)) {
        int ret = cma_alloc_port(ps, id_priv, rover);
        if (!ret)
            last_used_port = rover;
        if (ret!= -EADDRNOTAVAIL)
            return ret;
    }
    if (--remaining) {
        rover++;
        if ((rover < low) || (rover > high))
            rover = low;
        goto retry;
    }
    return -EADDRNOTAVAIL;
}