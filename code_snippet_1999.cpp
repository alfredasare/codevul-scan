xfs_attr_fork_remove(
	struct xfs_inode	*ip,
	struct xfs_trans	*tp)
{
	xfs_idestroy_fork(ip, XFS_ATTR_FORK);
	ip->i_d.di_forkoff = 0;
	ip->i_d.di_aformat = XFS_DINODE_FMT_EXTENTS;

	if (ip->i_d.di_anextents) {
		xfs_warn(ip->i_mount, "di_anextents not zero");
	}

	if (ip->i_afp) {
		xfs_warn(ip->i_mount, "i_afp is not NULL");
	}

	xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
}