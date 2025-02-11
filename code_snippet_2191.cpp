xfs_da_grow_inode(
	struct xfs_da_args	*args,
	xfs_dablk_t		*new_blkno)
{
	xfs_fileoff_t		bno;
	int			count;
	int			error;
	uint32_t		max_bno = XFS_MAX_FILEOFF; // Define max limit for bno
	uint32_t		max_count = INT_MAX; // Define max limit for count

	trace_xfs_da_grow_inode(args);

	if (args->whichfork == XFS_DATA_FORK) {
		bno = args->dp->i_mount->m_dirleafblk;
		count = args->dp->i_mount->m_dirblkfsbs;
	} else {
		bno = 0;
		count = 1;
	}

	// Verify bounds for bno and count
	if (bno > max_bno || count > max_count) {
		return -EOVERFLOW;
	}

	error = xfs_da_grow_inode_int(args, &bno, count);
	if (!error)
		*new_blkno = (xfs_dablk_t)bno;
	return error;
}