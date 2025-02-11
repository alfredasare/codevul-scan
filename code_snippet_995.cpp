void ext3_warning(struct super_block *sb, const char *function,
		  const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);

	printk(KERN_WARNING "EXT3-fs (%s): warning: %s\n",
	       sb->s_id, function);
	vprint_buf(fmt, args);

	va_end(args);
}

void vprint_buf(const char *fmt, va_list args)
{
	vscnprintf(buf, sizeof(buf), fmt, args);
	printk(KERN_WARNING "%s\n", buf);
}