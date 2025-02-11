gx_device_init(gx_device * dev, const gx_device * proto, gs_memory_t * mem, bool internal)
{
    // Validate and sanitize the proto pointer
    if (proto == NULL || proto->params_size <= 0) {
        return -1; // error
    }

    // Use a whitelist approach to restrict allowed values for params_size
    if (proto->params_size > GX_MAX_PARAMS_SIZE) {
        return -1; // error
    }

    // Allocate a new buffer for dev
    dev->params = malloc(proto->params_size);
    if (dev->params == NULL) {
        return -1; // error
    }

    // Copy trusted data into the dev structure
    if (proto->params_size > 0) {
        size_t copy_size = proto->params_size;
        if (copy_size > sizeof(dev->params)) {
            copy_size = sizeof(dev->params);
        }
        memcpy(dev->params, proto->params, copy_size);
    }

    dev->memory = mem;
    dev->retained =!internal;
    rc_init(dev, mem, (internal? 0 : 1));
    rc_increment(dev->icc_struct);
}