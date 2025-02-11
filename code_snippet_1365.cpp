static int btrfs_writepage_end_io_hook(struct page *page, u64 start, u64 end,
				       struct extent_state *state, int uptodate)
{
    //... (rest of the code remains the same)

    if (!btrfs_dec_test_ordered_pending(inode, &ordered_extent, start,
					    end - start + 1, uptodate))
        return 0;

    if (ordered_extent == NULL) {
        printk(KERN_ERR "ordered_extent is NULL\n");
        return -EINVAL;
    }

    //... (rest of the code remains the same)
}