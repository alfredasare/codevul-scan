#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <asm/page.h>
#include <asm/pgtable.h>

SYSCALL_DEFINE2(munlock, unsigned long, start, size_t, len)
{
	int ret;
	unsigned long end;

	if (!start || !len || (start & ~PAGE_MASK) || (end = PAGE_ALIGN(start + len)) > TASK_SIZE) {
		/* Invalid input parameters */
		return -EINVAL;
	}

	if (down_write_killable(&current->mm->mmap_sem))
		return -EINTR;
	ret = apply_vma_lock_flags(start, len, 0);
	up_write(&current->mm->mmap_sem);

	return ret;
}