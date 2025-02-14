void lock_two_nondirectories(struct inode *inode1, struct inode *inode2)
{
	if (&inode1 > &inode2) // Compare memory addresses
		swap(&inode1, &inode2);

	if (inode1 && !S_ISDIR(inode1->i_mode))
		inode_lock(inode1); // No need to cast, as it is correct
	if (inode2 && !S_ISDIR(inode2->i_mode) && inode2 != inode1)
		inode_lock_nested(inode2, I_MUTEX_NONDIR2); // No need to cast, as it is correct
}