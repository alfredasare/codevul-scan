int hid_input_report(struct hid_device *hid, int type, u8 *data, int size, int interrupt)
{
    struct hid_report_enum *report_enum;
    struct hid_driver *hdrv;
    struct hid_report *report;
    int ret = 0;

    if (!hid)
        return -ENODEV;

    if (down_trylock(&hid->driver_input_lock))
        return -EBUSY;

    if (!hid->driver) {
        ret = -ENODEV;
        goto unlock;
    }
    report_enum = hid->report_enum + type;
    hdrv = hid->driver;

    // Input validation for type
    if (type < 0 || type >= hid->report_enum_size) {
        dbg_hid("Invalid report type\n");
        ret = -EINVAL;
        goto unlock;
    }

    // Validate the size parameter
    if (!size) {
        dbg_hid("Empty report\n");
        ret = -1;
        goto unlock;
    }

    //...
}