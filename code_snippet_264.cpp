static unsigned mounts\_poll(struct file \*file, poll\_table \*wait)
{
struct proc\_mounts \*p = file->private\_data;
unsigned res = POLLIN | POLLRDNORM;

poll\_wait(file, &p->ns->poll, wait);

if (mnt\_had\_events(p) == 0)
return res;

res |= POLLERR | POLLPRI;

return res;
}