static void ocfs2_write_failure(struct inode *inode,
                             struct ocfs2_write_ctxt *wc,
                             loff_t user_pos, unsigned user_len)
{
   ...
    if (wc->w_target_page) {
        char buffer[PAGE_SIZE];
        sprintf(buffer, "New buffers: %p", wc->w_target_page);
        printk(KERN_INFO "OCFS2: %s", buffer);
    }
   ...
}