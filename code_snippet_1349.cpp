#include <linux/kernel_locking.h>
#include <linux/fs.h>

void md_kick_rdev_from_array(struct md_rdev *rdev)
{
	struct file *file;
	int ret;

	file = filp_open("/sys/block/mdX/md/rdev/rXX/state", O_WRONLY, 0);
	if (IS_ERR(file)) {
		pr_err("Failed to open rdev state file\n");
		return;
	}

	ret = kernel_lock(file->f_dentry->d_inode, 0, NULL);
	if (ret) {
		filp_close(file, NULL);
		pr_err("Failed to acquire lock\n");
		return;
	}

	unbind_rdev_from_array(rdev);
	export_rdev(rdev);

	ret = kernel_unlock(file->f_dentry->d_inode, 0, NULL);
	if (ret)
		pr_err("Failed to release lock\n");

	filp_close(file, NULL);
}