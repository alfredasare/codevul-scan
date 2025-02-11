#include <linux/fs.h>
#include <linux/namei.h>
#include <linux/mount.h>

int user_path_at(int dfd, const char __user *name, unsigned flags,
                 struct path *path)
{
	struct path path_result;
	int error;

	if (IS_ERR(copy_from_user(&path_result, &path, sizeof(path_result))))
		return PTR_ERR(path_result.dentry);

	error = open_namei_ns((const char *)path_result.dentry->d_name.name,
	                      flags, dfd, path, NULL, NFSD_VFSOP_OPEN);

	if (!error) {
		*path = path_result;
		/* Make sure the dentry is still valid */
		if (path_result.dentry && !path_result.dentry->d_inode)
			error = -ENODATA;
	}

	return error;
}