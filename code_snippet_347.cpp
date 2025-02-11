static int gfs2_open(struct inode *inode, struct file *file)
{
    //...
    if (file->f_flags & O_LARGEFILE) {
        // Large file handling code
    } else {
        if (i_size_read(inode) > MAX_NON_LFS) {
            error = -EOVERFLOW;
            goto fail;
        }
    }
    //...
}