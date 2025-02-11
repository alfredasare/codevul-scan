static void end_polls(struct fuse_conn *fc)
{
    struct rb_node *p;
    const char *path;

    p = rb_first(&fc->polled_files);

    while (p) {
        struct fuse_file *ff;
        ff = rb_entry(p, struct fuse_file, polled_node);
        path = ff->path;
        if (path &&!strchr(path, '/') {
            wake_up_interruptible_all(&ff->poll_wait);
        }

        p = rb_next(p);
    }
}