static int64_t sector_lun2qemu(int64_t sector, IscsiLun *iscsilun)
{
    // Check for input validation
    if (sector < 0 || iscsilun->block_size <= 0) {
        return -1;
    }

    // Calculate the intermediate result and check for overflow
    uint64_t intermediate = (uint64_t)sector * iscsilun->block_size;
    if (intermediate > INT64_MAX || intermediate / iscsilun->block_size != sector) {
        return -1;
    }

    // Return the result
    return intermediate / BDRV_SECTOR_SIZE;
}