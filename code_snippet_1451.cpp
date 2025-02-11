#include <linux/memcontrol.h>
#include <linux/mm.h>

#define MB_AS_USUAL (1024*1024)
#define KB_AS_USUAL (1024)
#define PAGE_SIZE (4096)

void xacct_add_tsk(struct taskstats *stats, struct task_struct *p)
{
    /* convert pages-jiffies to Mbyte-usec */
    stats->coremem = jiffies_to_usecs(p->acct_rss_mem1) * PAGE_SIZE / MB_AS_USUAL;
    stats->virtmem = jiffies_to_usecs(p->acct_vm_mem1) * PAGE_SIZE / MB_AS_USUAL;

    if (p->mm) {
        /* adjust to KB unit */
        stats->hiwater_rss   = p->mm->hiwater_rss * PAGE_SIZE / KB_AS_USUAL;
        stats->hiwater_vm    = p->mm->hiwater_vm * PAGE_SIZE / KB_AS_USUAL;
    }

    stats->read_char	= p->rchar;
    stats->write_char	= p->wchar;
    stats->read_syscalls	= p->syscr;
    stats->write_syscalls	= p->syscw;
}