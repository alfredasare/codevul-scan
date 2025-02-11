#include <linux/kernel.h>
#include <linux/safe_arithmetic.h>

void xacct_add_tsk(struct taskstats *stats, struct task_struct *p)
{
	/* convert pages-jiffies to Mbyte-usecs */
	u64 coremem_usecs = jiffies_to_usecs(p->acct_rss_mem1);
	u64 virtmem_usecs = jiffies_to_usecs(p->acct_vm_mem1);

	if (!safe_div(coremem_usecs * PAGE_SIZE, MB, &stats->coremem)) {
		/* Handle integer overflow or clamp value if needed */
		stats->coremem = ULONG_MAX;
	}

	if (!safe_div(virtmem_usecs * PAGE_SIZE, MB, &stats->virtmem)) {
		/* Handle integer overflow or clamp value if needed */
		stats->virtmem = ULONG_MAX;
	}

	if (p->mm) {
		/* adjust to KB unit */
		stats->hiwater_rss   = clamp_val(p->mm->hiwater_rss * PAGE_SIZE, ULONG_MAX);
		stats->hiwater_vm    = clamp_val(p->mm->hiwater_vm * PAGE_SIZE, ULONG_MAX);
	}

	stats->read_char	= p->rchar;
	stats->write_char	= p->wchar;
	stats->read_syscalls	= p->syscr;
	stats->write_syscalls	= p->syscw;
}