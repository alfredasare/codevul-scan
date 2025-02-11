int vfs\_rmdir(struct inode \*dir, struct dentry \*dentry)
{
if (!dentry || !dir)
return -EINVAL;

int error = may\_delete(dir, dentry, 1);

if (error)
return error;

if (!dir->i\_op->rmdir)
return -EPERM;

vfs\_dq\_init(dir);

mutex\_lock(&dentry->d\_inode->i\_mutex);
dentry\_unhash(dentry);
if (d\_mountpoint(dentry))
error = -EBUSY;
else {
error = security\_inode\_rmdir(dir, dentry);
if (!error) {
error = dir->i\_op->rmdir(dir, dentry);
if (!error)
dentry->d\_inode->i\_flags |= S\_DEAD;
}
}
mutex\_unlock(&dentry->d\_inode->i\_mutex);
if (!error) {
d\_delete(dentry);
}
dput(dentry);

return error;
}