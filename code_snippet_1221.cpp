static int64_t sector_lun2qemu(int64_t sector, IscsiLun *iscsilun)
{
    __uint128_t result = (uint64_t)sector * (uint64_t)iscsilun->block_size;
    return (int64_t)(result / BDRV_SECTOR_SIZE);
}