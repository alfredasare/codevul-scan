xfs_da_get_buf(
	struct xfs_trans	*trans,
	struct xfs_inode	*dp,
	xfs_dablk_t		bno,
	xfs_daddr_t		mappedbno,
	struct xfs_buf		**bpp,
	int			whichfork)
{
	struct xfs_buf		*bp;
	struct xfs_buf_map	map;
	struct xfs_buf_map	*mapp;
	int			nmap;
	int			errcode;

	*bpp = NULL;
	mapp = &map;
	nmap = 1;
	try {
		errcode = xfs_dabuf_map(trans, dp, bno, mappedbno, whichfork,
						&mapp, &nmap);
		if (errcode) {
			/* mapping a hole is not an error, but we don't continue */
			if (errcode == -1)
				errcode = 0;
			goto out;
		}

		bp = xfs_trans_get_buf_map(trans, dp->i_mount->m_ddev_targp,
					mapp, nmap, 0);
		errcode = bp? bp->b_error : XFS_ERROR(EIO);
		if (errcode) {
			xfs_trans_brelse(trans, bp);
			goto out;
		}

		*bpp = bp;
		return 0;
	} catch (int err) {
		errcode = err;
		goto out;
	}
out:
	if (mapp != &map)
		kmem_free(mapp);
	return errcode;
}