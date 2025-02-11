#include <linux/mutex.h>

static DEFINE_MUTEX(shmem_create_mutex);

static int shmem_create(struct inode *dir, struct dentry *dentry, umode_t mode,
                        bool excl)
{
    int ret;
    struct dentry *existing_dentry;

    mutex_lock(&shmem_create_mutex);

    existing_dentry = lookup_one_len(dentry->d_name.name, dir, dentry->d_name.len);
    if (existing_dentry) {
        mutex_unlock(&shmem_create_mutex);
        return -EEXIST;
    }

    ret = shmem_mknod(dir, dentry, mode | S_IFREG, 0);

    mutex_unlock(&shmem_create_mutex);

    return ret;
}