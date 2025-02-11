xfs_attr_leaf_get(xfs_da_args_t *args)
{
    struct xfs_buf *bp;
    int error;

    trace_xfs_attr_leaf_get(args);

    uint32_t blkno = 0;
    error = xfs_attr3_leaf_read(args->trans, args->dp, &blkno, -1, &bp);
    if (error)
        return error;

    uint64_t rmtblkno = args->rmtblkno;
    error = xfs_attr3_leaf_lookup_int(bp, args);
    if (error!= EEXIST)  {
        xfs_trans_brelse(args->trans, bp);
        return error;
    }
    error = xfs_attr3_leaf_getvalue(bp, args);
    xfs_trans_brelse(args->trans, bp);
    if (!error && (rmtblkno > 0) &&!(args->flags & ATTR_KERNOVAL)) {
        error = xfs_attr_rmtval_get(args);
    }
    return error;
}