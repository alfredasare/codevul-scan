void ext3_warning(struct super_block *sb, const char *function, const char *fmt,...)
{
    char buffer[1024]; // Set a reasonable buffer size
    vsnprintf(buffer, sizeof(buffer), fmt, (va_list){&fmt, &function, &sb->s_id});

    printk(KERN_WARNING "EXT3-fs (%s): warning: %s: %s\n", sb->s_id, function, buffer);
}