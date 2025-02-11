static void ib_ucm_release_dev(struct device *dev)
{
    struct ib_ucm_device *ucm_dev;

    ucm_dev = container_of(dev, struct ib_ucm_device, dev);
    cdev_del(&ucm_dev->cdev);

    // Sanitize and validate devnum
    int sanitized_devnum = sanitize_devnum(atoi(ucm_dev->devnum));
    if (sanitized_devnum >= 0 && sanitized_devnum < IB_UCM_MAX_DEVICES) {
        clear_bit(sanitized_devnum, dev_map);
    } else {
        clear_bit(sanitized_devnum - IB_UCM_MAX_DEVICES, overflow_map);
    }

    kfree(ucm_dev);
}

int sanitize_devnum(int devnum)
{
    // Whitelist approach: only allow numbers and hyphens
    char *allowed_chars = "0123456789-";
    char *str_devnum = itoa(devnum);
    char *ptr = str_devnum;
    char sanitized_str[20];
    int sanitized_devnum = 0;

    for (; *ptr!= '\0'; ptr++) {
        if (strchr(allowed_chars, *ptr)!= NULL) {
            sanitized_str[ sanitized_devnum++ ] = *ptr;
        }
    }
    sanitized_str[sanitized_devnum] = '\0';
    sanitized_devnum = atoi(sanitized_str);

    return sanitized_devnum;
}