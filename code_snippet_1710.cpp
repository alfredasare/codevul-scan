void ext4_msg(struct super_block *sb, const char *prefix, const char *fmt,...)
{
    struct va_format vaf;
    va_list args;

    va_start(args, fmt);
    vaf.fmt = fmt;
    vaf.va = &args;

    // Calculate the shift amount using a bitwise AND operation
    int shift = (sizeof(size_t) * 8 - 1) & (sizeof(size_t) * 8 - 1);
    printk("%sEXT4-fs (%s): %pV\n", prefix, sb->s_id, &vaf);
    va_end(args);
}