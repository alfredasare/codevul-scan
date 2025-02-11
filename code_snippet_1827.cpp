#define FS_CTX_OPEN_FLAGS O_PATH

static int handle_open2(FsContext *fs_ctx, V9fsPath *dir_path, const char *name,
                        int flags, FsCred *credp, V9fsFidOpenState *fs)
{
    //...
    dirfd = open_by_handle(data->mountfd, dir_path->data, FS_CTX_OPEN_FLAGS);
    //...
}