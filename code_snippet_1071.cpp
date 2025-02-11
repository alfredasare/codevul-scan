struct dentry *lock_rename(struct dentry *p1, struct dentry *p2)
{
	struct dentry *p;
	int unlock_p1 = 0, unlock_p2 = 0;

	if (p1 == p2) {
		mutex_lock_nested(&p1->d_inode->i_mutex, I_MUTEX_PARENT);
		return NULL;
	}

	mutex_lock(&p1->d_inode->i_sb->s_vfs_rename_mutex);

	p = d_ancestor(p2, p1);
	if (p) {
		mutex_lock_nested(&p2->d_inode->i_mutex, I_MUTEX_PARENT);
		unlock_p1 = 1;
		p = d_ancestor(p1, p2);
		if (p) {
			mutex_lock_nested(&p1->d_inode->i_mutex, I_MUTEX_PARENT);
			unlock_p2 = 1;
			return p;
		}
		mutex_unlock(&p1->d_inode->i_sb->s_vfs_rename_mutex);
		if (unlock_p2)
			mutex_unlock(&p2->d_inode->i_mutex);
	} else {
		p = d_ancestor(p1, p2);
		if (p) {
			mutex_lock_nested(&p1->d_inode->i_mutex, I_MUTEX_PARENT);
			unlock_p2 = 1;
			return p;
		}
		mutex_unlock(&p1->d_inode->i_sb->s_vfs_rename_mutex);
	}

	mutex_lock_nested(&p1->d_inode->i_mutex, I_MUTEX_PARENT);
	mutex_lock_nested(&p2->d_inode->i_mutex, I_MUTEX_CHILD);
	if (unlock_p1)
		mutex_unlock(&p1->d_inode->i_mutex);
	if (unlock_p2)
		mutex_unlock(&p2->d_inode->i_mutex);
	return NULL;
}