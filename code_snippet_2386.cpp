ext4_xattr_delete_inode(handle_t *handle, struct inode *inode)
{
    struct buffer_head *bh = NULL;
    uint64_t file_acl = EXT4_I(inode)->i_file_acl; // Use a 64-bit integer to avoid overflow

    if (!file_acl)
        goto cleanup;
    bh = sb_bread(inode->i_sb, file_acl);
    if (!bh) {
        EXT4_ERROR_INODE(inode, "block %llu read error", file_acl);
        goto cleanup;
    }
    if (BHDR(bh)->h_magic!= cpu_to_le32(EXT4_XATTR_MAGIC) ||
        BHDR(bh)->h_blocks!= cpu_to_le32(1)) {
        EXT4_ERROR_INODE(inode, "bad block %llu", file_acl);
        goto cleanup;
    }
    ext4_xattr_release_block(handle, inode, bh);
    EXT4_I(inode)->i_file_acl = 0;

cleanup:
    brelse(bh);
}