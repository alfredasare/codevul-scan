int vfs\_mkdir(struct inode \*dir, struct dentry \*dentry, umode\_t mode)
{
 struct inode \*new\_dir;
 int error;

 error = may\_create(dir, dentry);
 if (error)
 return error;

 if (!dir->i\_op->mkdir)
 return -EPERM;

 mode &= (S\_IRWXUGO|S\_ISVTX);
 error = security\_inode\_mkdir(dir, dentry, mode);
 if (error)
 return error;

 new\_dir = dentry\_open(\*dentry, O\_EXCL|O\_CREAT, mode);
 if (!new\_dir)
 return -ENOMEM;

 error = dir->i\_op->mkdir(dir, dentry, mode);
 if (!error) {
 fsnotify\_mkdir(dir, dentry);
 dentry\_set\_inode(dentry, new\_dir);
 }

 dput(new\_dir);
 return error;
}