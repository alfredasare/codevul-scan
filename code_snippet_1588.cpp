long hugetlb_unreserve_pages(struct inode *inode, long start, long end,
							long freed)
{
	struct hstate *h = hstate_inode(inode);
	struct resv_map *resv_map = inode_resv_map(inode);
	long chg = 0;
	struct hugepage_subpool *spool = subpool_inode(inode);
	long gbl_reserve;

	if (resv_map)
		chg = region_del(resv_map, start, end);
	else
		return -EINVAL; /* Invalid argument */

	spin_lock(&inode->i_lock);
	inode->i_blocks -= (blocks_per_huge_page(h) * freed);
	spin_unlock(&inode->i_lock);

	gbl_reserve = hugepage_subpool_put_pages(spool, (chg - freed));
	hugetlb_acct_memory(h, -gbl_reserve);

	return 0;
}