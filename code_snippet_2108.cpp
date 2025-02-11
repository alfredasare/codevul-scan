static int ext2_freeze(struct super_block *sb)
{
    struct ext2_sb_info *sbi = EXT2_SB(sb);
    unsigned long remove_count;

    if ((remove_count = atomic_long_read(&sb->s_remove_count)) > 0) {
        ext2_sync_fs(sb, 1);
        return 0;
    }
    //...
}