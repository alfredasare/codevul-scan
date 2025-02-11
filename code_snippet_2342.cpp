static int ext2_freeze(struct super_block *sb)
{
	struct ext2_sb_info *sbi = EXT2_SB(sb);

	/*
	 * Open but unlinked files present? Keep EXT2_VALID_FS flag cleared
	 * because we have unattached inodes and thus filesystem is not fully
	 * consistent.
	 */
	if (atomic_long_read(&sb->s_remove_count)) {
		ext2_sync_fs(sb, 1);
		return 0;
	}
	/* Set EXT2_FS_VALID flag */
	mutex_lock(&sbi->s_umount);
	sbi->s_es->s_state = cpu_to_le16(sbi->s_mount_state);
	mutex_unlock(&sbi->s_umount);
	ext2_sync_super(sb, sbi->s_es, 1);

	return 0;
}