xfs\_vn\_mknod(struct inode *dir, struct dentry *dentry, umode\_t mode, dev\_t rdev)
{
 struct dentry *safe\_dentry;

 safe\_dentry = dentry;

 /* Ensure that 'dentry' cannot change after this point */
 lock\_dentry(dentry);

 if (d\_is\_positive(dentry)) {
 if (!d\_is\_negative(safe\_dentry))
 return -EEXIST;
 } else {
 if (d\_is\_negative(safe\_dentry))
 return -ENOENT;
 }

 return xfs\_generic\_create(dir, safe\_dentry, mode, rdev, false);
}