#include <linux/types.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/key.h>
#include <linux/cred.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#include <linux/init.h>

#define PATH_MAX 4096

static int call_usermodehelper_keys(const char *path, const char **argv, const char **envp,
                                   struct key *session_keyring, int wait)
{
    struct subprocess_info *info;

    // Validate path
    if (!path || strlen(path) >= PATH_MAX) {
        return -EINVAL;
    }

    // Validate argv and envp (optional)
    if (!argv || !envp) {
        return -EINVAL;
    }

    info = call_usermodehelper_setup(path, argv, envp, GFP_KERNEL,
                                      umh_keys_init, umh_keys_cleanup,
                                      session_keyring);
    if (!info)
        return -ENOMEM;

    key_get(session_keyring);
    return call_usermodehelper_exec(info, wait);
}