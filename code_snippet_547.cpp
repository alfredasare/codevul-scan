static void change_curseg(struct f2fs_sb_info *sbi, int type)
{
	struct dirty_seglist_info *dirty_i = DIRTY_I(sbi);
	struct curseg_info *curseg = CURSEG_I(sbi, type);
	unsigned int new_segno = curseg->next_segno;
	struct f2fs_summary_block *sum_node;
	struct page *sum_page;
	unsigned int sum_blk_index;

	sum_blk_index = GET_SUM_BLOCK(sbi, curseg->segno);

	// Validate the sum_blk_index
	if (sum_blk_index >= sbi->sb->s_blocks_count) {
		pr_err("Invalid summary block index: %u\n", sum_blk_index);
		return;
	}

	write_sum_page(sbi, curseg->sum_blk, sum_blk_index);

	__set_test_and_inuse(sbi, new_segno);

	mutex_lock(&dirty_i->seglist_lock);
	__remove_dirty_segment(sbi, new_segno, PRE);
	__remove_dirty_segment(sbi, new_segno, DIRTY);
	mutex_unlock(&dirty_i->seglist_lock);

	reset_curseg(sbi, type, 1);
	curseg->alloc_type = SSR;
	__next_free_blkoff(sbi, curseg, 0);

	sum_page = get_sum_page(sbi, new_segno);
	if (!sum_page) {
		pr_err("Failed to get summary page\n");
		return;
	}

	sum_blk_index = GET_SUM_BLOCK(sbi, new_segno);

	// Validate the sum_blk_index
	if (sum_blk_index >= sbi->sb->s_blocks_count) {
		pr_err("Invalid summary block index: %u\n", sum_blk_index);
		f2fs_put_page(sum_page, 1);
		return;
	}

	sum_node = (struct f2fs_summary_block *)page_address(sum_page);
	memcpy(curseg->sum_blk, sum_node, SUM_ENTRY_SIZE);
	f2fs_put_page(sum_page, 1);
}