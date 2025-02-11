static void unmap_underlying_metadata_blocks(struct block_device *bdev, sector_t block, int count)
{
    mutex_lock(&unmap_mutex); // acquire the lock
    int i;
    for (i = 0; i < count; i++)
        unmap_underlying_metadata(bdev, block + i);
    mutex_unlock(&unmap_mutex); // release the lock
}