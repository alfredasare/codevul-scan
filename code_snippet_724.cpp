static void unmap_underlying_metadata_blocks(struct block_device *bdev,
sector_t block, int count)
{
sector_t max_blocks = bdev->size >> bdev->block\_size\_bits;
if (count > max_blocks - block) {
count = max_blocks - block;
pr\_warn("Attempt to unmap more blocks than available\n");
}
int i;
for (i = 0; i < count; i++)
unmap\_underlying\_metadata(bdev, block + i);
}