int LELib_Create(const effect_uuid_t *uuid,
                 int32_t sessionId,
                 int32_t ioId,
                 effect_handle_t *pHandle) {
    ALOGV("LELib_Create()");
    int ret;
    int i;

    if (pHandle == NULL || uuid == NULL) {
        return -EINVAL;
    }

    // Validate and sanitize the uuid parameter
    char *uuid_str = (char *)uuid;
    char *ptr = strchr(uuid_str, '/');
    if (ptr!= NULL) {
        ALOGE("Invalid UUID: %s", uuid_str);
        return -EINVAL;
    }

    ptr = strchr(uuid_str, '*');
    if (ptr!= NULL) {
        ALOGE("Invalid UUID: %s", uuid_str);
        return -EINVAL;
    }

    // Rest of the function remains the same
    //...
}