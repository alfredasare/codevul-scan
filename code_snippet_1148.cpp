enum media_device_error {
    MEDIA_DEVICE_ERROR_GENERIC,
    MEDIA_DEVICE_ERROR_INVALID_PARAMETER,
    // Add more error codes as needed
};

static long media_device_enum_entities(struct media_device *mdev,
				       struct media_entity_desc __user *uent)
{
    //...

    if (copy_from_user(&u_ent.id, &uent->id, sizeof(u_ent.id)))
        return media_device_error(MEDIA_DEVICE_ERROR_GENERIC, "Copy from user failed");

    ent = find_entity(mdev, u_ent.id);
    if (ent == NULL)
        return media_device_error(MEDIA_DEVICE_ERROR_INVALID_PARAMETER, "Entity not found");

    //...
}

static enum media_device_error media_device_error(enum media_device_error code, char *message)
{
    printk(KERN_WARNING "media_device: %s\n");
    return code;
}