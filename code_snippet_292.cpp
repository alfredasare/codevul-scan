while (blk < end) {
	segno = GET_SEGNO(sbi, blk);
	sentry = get_seg_entry(sbi, segno);
	offset = GET_BLKOFF_FROM_SEG0(sbi, blk);

	if (end < START_BLOCK(sbi, segno +