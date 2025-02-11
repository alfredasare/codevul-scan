struct file *ovl_path_open(struct path *path, int flags)
{
    struct file *file = NULL;
    int ret;

    try {
        file = dentry_open(path, flags, current_cred());
    } catch (const std::exception& e) {
        if (file) {
            fput(file);
        }
        throw e; // rethrow the exception
    } catch (...) {
        if (file) {
            fput(file);
        }
        throw;
    }

    return file;
}