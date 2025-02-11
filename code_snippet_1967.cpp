static int handle\_open2(FsContext \*fs\_ctx, V9fsPath \*dir\_path, const char \*name,
int flags, FsCred \*credp, V9fsFidOpenState \*fs)
{
int ret;
int dirfd, fd;
struct handle\_data \*data = (struct handle\_data \*)fs\_ctx->private;

dirfd = open\_by\_handle(data->mountfd, dir\_path->data, O\_PATH);
if (dirfd > 0) { // Check for positive return value
fd = openat(dirfd, name, flags | O\_NOFOLLOW, credp->fc\_mode);
if (fd >= 0) {
ret = handle\_update\_file\_cred(dirfd, name, credp);
if (ret < 0) {
close(fd);
fd = ret;
} else {
fs->fd = fd;
}
}
close(dirfd);
}
return fd;
}