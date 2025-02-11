SYSCALL_DEFINE3(inotify\_add\_watch, int, fd, const char \_\_user \*, pathname,
u32, mask)
{
struct fsnotify\_group \*group;
struct inode \*inode;
struct path path;
struct file \*filp;
int ret, fput\_needed;
unsigned flags = 0;

filp = fget\_light(fd, &fput\_needed);
if ( unlikely(!filp) )
return -EBADF;

/* verify that this is indeed an inotify instance */
if ( unlikely(filp->f\_op != &inotify\_fops) ) {
ret = -EINVAL;
goto fput\_and\_out;
}

ret = security\_inotify\_create\_file\_check(filp);
if (ret < 0)
goto fput\_and\_out;

if (!(mask & IN\_DONT\_FOLLOW))
flags |= LOOKUP\_FOLLOW;
if (mask & IN\_ONLYDIR)
flags |= LOOKUP\_DIRECTORY;

down\_read(&filp->f\_dentry->d\_lock);
ret = user_path_at(AT\_FDCWD, filp, pathname, &path, flags);
up\_read(&filp->f\_dentry->d\_lock);
if (ret)
goto fput\_and\_out;

/* inode held in place by reference to path; group by fget on fd */
inode = path.dentry->d\_inode;
group = filp->private\_data;

/* create/update an inode mark */
ret = inotify\_update\_watch(group, inode, mask);
path\_put(&path);
fput\_and\_out:
fput\_light(filp, fput\_needed);
return ret;
}