#include <linux/cred.h>

static int get_fsuid(void)
{
    return current_uid().val;
}