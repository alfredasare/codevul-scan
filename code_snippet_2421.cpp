#include <linux/limits.h>

int pt_removexattr(FsContext *ctx, const char *path, const char *name)
{
    if (!name || strlen(name) > MAX_XATTR_NAME_SIZE) {
        return -EINVAL;
    }

    return local_removexattr_nofollow(ctx, path, name);
}