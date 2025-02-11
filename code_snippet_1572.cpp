static int exitcode\_proc\_open(struct inode \*inode, struct file \*file)
{
 return single\_open(file, (int(*)(struct seq\_file *, void \*))exitcode\_proc\_show, NULL);
}