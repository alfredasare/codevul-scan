static ssize_t vfs\_pwrite\_fn(void \*file, const void \*buf, size\_t len, off\_t offset)
{
 struct files\_struct \*fsp = NULL;
 ssize\_t result;

 fsp = (struct files\_struct \*)file;

 mutex\_lock(&fsp->files\_mutex);
 result = SMB\_VFS\_PWRITE(fsp, buf, len, offset);
 mutex\_unlock(&fsp->files\_mutex);

 return result;
}