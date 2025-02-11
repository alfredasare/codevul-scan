static int bochs_read(BlockDriverState *bs, int64_t sector_num,
                       uint8_t *buf, int nb_sectors)
{
    int64_t block_offset = 0;
    int ret = 0;
    uint32_t sectors_left = nb_sectors; 

    while (sectors_left > 0) {
        block_offset = (uint32_t)seek_to_sector(bs, sector_num); 
        if (block_offset >= 0) {
            ret = bdrv_pread(bs->file, (uint32_t)block_offset, buf, 512);
            if (ret!= 512) {
                return -1;
            }
        } else
            memset(buf, 0, 512);
        sectors_left--;
        sector_num++;
        buf += 512;
    }
    return 0;
}