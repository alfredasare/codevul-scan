#include <stdlib.h>

static void imapd_check(struct backend *be, int usinguid)
{
    if (backend_current && backend_current != be) {
        /* remote mailbox */
        char *mytag_escaped = NULL;
        size_t mytag_len =