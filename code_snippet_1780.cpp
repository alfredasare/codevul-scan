static int rb_check_bpage(struct ring_buffer_per_cpu *cpu_buffer,
			  struct buffer_page *bpage)
{
#ifdef CONFIG_DEBUG_RB
	if (!bpage || !buffer_page_vaddr(bpage)) {
		pr_err("Invalid bpage pointer!\n");
		return -EINVAL;
	}
#endif

	unsigned long val = (unsigned long)bpage;

	if (RB_WARN_ON(cpu_buffer, val & RB_FLAG_MASK))
		return 1;

	return 0;
}