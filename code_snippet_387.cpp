static void acquire_freeze_lock(struct super_block *sb, int level, bool trylock,
                                unsigned long ip)
{
	rwsem_acquire_read(&sb->s_writers.lock_map[level-1], 0, trylock, ip);
}