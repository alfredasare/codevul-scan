void __check_sit_bitmap(struct f2fs_sb_info *sbi, block_t start, block_t end) {
#ifdef CONFIG_F2FS_CHECK_FS
    struct seg_entry *sentry;
    unsigned int segno;
    block_t blk = start;
    unsigned long offset, size, max_blocks = sbi->blocks_per_seg;
    unsigned long *map;

    if (start >= end) {
        f2fs_err(sbi, "Invalid input: start >= end");
        return;
    }

    while (blk < end) {
        segno = GET_SEGNO(sbi, blk);
        sentry = get_seg_entry(sbi, segno);
        offset = GET_BLKOFF_FROM_SEG0(sbi, blk);

        size = (unsigned long)(end - blk);
        if (size > max_blocks) {
            f2fs_err(sbi, "Buffer overflow: size exceeds max blocks");
            return;
        }

        map = (unsigned long *)(sentry->cur_valid_map);
        offset = __find_rev_next_bit(map, size, offset);
        f2fs_bug_on(sbi, offset!= size);
        blk = START_BLOCK(sbi, segno + 1);
    }
#endif
}