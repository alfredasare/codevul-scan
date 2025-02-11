static int ext4_key_prefix(struct inode *inode, u8 **key)
{
	int key_prefix_size = EXT4_SB(inode->i_sb)->key_prefix_size;

	if (key_prefix_size < 0 || key_prefix_size >= EXT4_KEY_PREFIX_SIZE) {
		return -EINVAL;
	}

	*key = kmalloc(key_prefix_size, GFP_KERNEL);
	if (!*key) {
		return -ENOMEM;
	}

	memcpy(*key, EXT4_SB(inode->i_sb)->key_prefix, key_prefix_size);

	return key_prefix_size;
}