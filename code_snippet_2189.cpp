static int ext4_xattr_fiemap(struct inode *inode,
			     struct fiemap_extent_info *fieinfo)
{
    //...

    error = ext4_get_inode_loc(inode, &iloc);
    if (error)
        return error;

    if (!iloc.bh) {
        brelse(NULL);
        return -EFAULT;
    }

    physical = (__u64)iloc.bh->b_blocknr << blockbits;
    offset = EXT4_GOOD_OLD_INODE_SIZE +
             EXT4_I(inode)->i_extra_isize;
    physical += offset;
    length = EXT4_SB(inode->i_sb)->s_inode_size - offset;
    flags |= FIEMAP_EXTENT_DATA_INLINE;
    brelse(iloc.bh);
}