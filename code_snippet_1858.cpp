void ext4_msg(struct super_block *sb, const char *prefix, const char *fmt, ...)
{
    struct va_format vaf;
    va_list args;
    size_t prefix_len;

    if (!sb || !prefix || !fmt) {
        printk(KERN_ERR "Invalid input\n");
        return;