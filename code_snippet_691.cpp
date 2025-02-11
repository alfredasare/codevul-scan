static int udf_rmdir(struct inode *dir, struct dentry *dentry)
{
    //...
    if (inode->i_nlink!= 2)
    {
        printk(KERN_ERR "Error: empty directory has incorrect link count\n");
        clear_nlink(inode);
    }
    //...
}