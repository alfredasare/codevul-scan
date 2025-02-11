#include <string.h>
#include <ctype.h>

#define IS_VALID_CHAR(c) isalnum(c) || c == '_' || c == '-'

int is_command_valid(const char *command) {
    int i;
    if (strcmp(command, "some_known_safe_command") == 0) {
        return 1;
    }
    for (i = 0; command[i]; i++) {
        if (!IS_VALID_CHAR(command[i])) {
            return 0;
        }
    }
    return 1;
}

void mm_audit_run_command(const char *command) {
    Buffer m;

    debug3("%s entering command %s", __func__, command);

    if (!is_command_valid(command)) {
        debug3("%s invalid command: %s", __func__, command);
        return;
    }

    buffer_init(&m);
    buffer_put_cstring(&m, command);

    mm_request_send(pmonitor->m_recvfd, MONITOR_REQ_AUDIT_COMMAND, &m);
    buffer_free(&m);
}