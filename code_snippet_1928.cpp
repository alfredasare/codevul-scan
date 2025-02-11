int xfs_buf_vmap_len(struct xfs_buf *bp)
{
    int len = PAGE_SIZE;
    if (bp->b_page_count > 0 && bp->b_offset < PAGE_SIZE)
        len = (bp->b_page_count - 1) * PAGE_SIZE + PAGE_SIZE - bp->b_offset;
    return len;
}