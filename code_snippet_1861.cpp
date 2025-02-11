xfs_attr_fork_remove(
    struct xfs_inode	*ip,
    struct xfs_trans	*tp)
{
    xfs_idestroy_fork(ip, XFS_ATTR_FORK);
    ip->i_d.di_forkoff = 0;
    ip->i_d.di_aformat = XFS_DINODE_FMT_EXTENTS;

    int i = 0;
    for (; i < 100 && ip->i_d.di_anextents > 0; i++) {
        ASSERT(ip->i_d.di_anextents > 0);
        ASSERT(ip->i_afp == NULL);

        xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
        ip->i_d.di_anextents--;
    }
}