static int ext4_key_prefix(struct inode *inode, u8 **key)
{
    u32 key_prefix_size = EXT4_SB(inode->i_sb)->key_prefix_size;
    u8 *key_ptr = EXT4_SB(inode->i_sb)->key_prefix;

    if (key_prefix_size > sizeof(*key_ptr)) {
        // Handle error or return an error code
    }

    *key = kmemdup(key_ptr, key_prefix_size, GFP_KERNEL);
    if (*key == NULL) {
        // Handle error or return an error code
    }

    return key_prefix_size;
}