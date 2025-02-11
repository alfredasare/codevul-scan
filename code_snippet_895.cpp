#include <linux/mutex.h>

static DEFINE_MUTEX(umount_mutex);

int may_umount_tree(struct vfsmount *m)
{
	struct mount *mnt = real_mount(m);
	int actual_refs = 0;
	int minimum_refs = 0;
	struct mount *p;
	BUG_ON(!m);

	mutex_lock(&umount_mutex);

	/* write lock needed for mnt_get_count */
	br_write_lock(&vfsmount_lock);
	for (p = mnt; p; p = next_mnt(p, mnt)) {
		actual_refs += mnt_get_count(p);
		minimum_refs += 2;
	}
	br_write_unlock(&vfsmount_lock);

	if (actual_refs > minimum_refs) {
		mutex_unlock(&umount_mutex);
		return 0;
	}

	/* Perform unmount operations here */

	mutex_unlock(&umount_mutex);
	return 1;
}