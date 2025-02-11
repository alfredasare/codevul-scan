static struct inode * get_pipe_inode(void)
{
    struct inode *inode = new_inode_pseudo(pipe_mnt->mnt_sb);
    struct pipe_inode_info *pipe = NULL; // Initialize pipe to NULL

    if (!inode)
        goto fail_inode;

    inode->i_ino = get_next_ino();

    pipe = alloc_pipe_info();
    if (!pipe) {
        iput(inode); // Put inode back before returning NULL
        return NULL;
    }

    inode->i_pipe = pipe;
    pipe->files = 2;
    pipe->readers = pipe->writers = 1;
    inode->i_fop = &pipefifo_fops;

    inode->i_state = I_DIRTY;
    inode->i_mode = S_IFIFO | S_IRUSR | S_IWUSR;
    inode->i_uid = current_fsuid();
    inode->i_gid = current_fsgid();
    inode->i_atime = inode->i_mtime = inode->i_ctime = CURRENT_TIME;

    return inode;
}