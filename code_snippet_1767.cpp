xfs_queue_cowblocks(
	struct xfs_mount *mp)
{
	int cowb_set;

	rcu_read_lock();
	cowb_set = radix_tree_tagged(&mp->m_perag_tree, XFS_ICI_COWBLOCKS_TAG);
	if (cowb_set)
		queue_delayed_work(mp->m_eofblocks_workqueue,
				   &mp->m_cowblocks_work,
				   msecs_to_jiffies(xfs_cowb_secs * 1000));
	rcu_read_unlock();
}