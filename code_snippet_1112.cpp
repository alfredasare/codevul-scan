static struct PointerBarrierDevice *AllocBarrierDevice(size_t max_deviceid)
{
    struct PointerBarrierDevice *pbd = NULL;

    if (max_deviceid >= SIZE_MAX - sizeof(struct PointerBarrierDevice)) {
        return NULL;
    }

    pbd = malloc(sizeof(struct PointerBarrierDevice) + max_deviceid * sizeof(int));

    if (!pbd)
        return NULL;

    pbd->deviceid = -1; /* must be set by caller */
    pbd->barrier_event_id = 1;
    pbd->release_event_id = 0;
    pbd->hit = FALSE;
    pbd->seen = FALSE;
    xorg_list_init(&pbd->entry);

    return pbd;
}