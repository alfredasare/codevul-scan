#include <string.h> /* for strlen() */

#define MAX_ARCH_LENGTH 32 /* Define an appropriate maximum length for the 'arch' field */

TargetInfo *qmp_query_target(Error **errp)
{
    TargetInfo *info = g_malloc0(sizeof(*info));

    size_t target_name_len = strlen(TARGET_NAME);

    /* Check if the input length is within bounds */
    if (target_name_len > 0 && target_name_len < MAX_ARCH_LENGTH) {
        info->arch = strncpy(g_new0(char, MAX_ARCH_LENGTH), TARGET_NAME, MAX_ARCH_LENGTH - 1);
    } else {
        /* Handle the error case, e.g., set error and return NULL */
        g_free(info);
        return NULL;
    }

    return info;
}