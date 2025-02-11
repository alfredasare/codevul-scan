static struct kobject *floppy_find(dev_t dev, int *part, void *data)
{
    int drive = (*part & 3) | ((*part & 0x80) >> 5);
    if (drive < 0 || drive >= N_DRIVE ||!floppy_available(drive)) {
        return NULL;
    }
    if ((*part >> 2) >= ARRAY_SIZE(floppy_type)) {
        return NULL;
    }
    *part = 0;
    return get_safe_disk(disks, drive);
}

struct kobject *get_safe_disk(struct disk **disks, int index, int (*bounds_check)(int))
{
    if (index < 0 || index >= N_DISK) {
        return NULL;
    }
    return disks[index];
}