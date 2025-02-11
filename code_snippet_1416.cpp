#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

static int cmd_mv(void *data, const char *input) {
    static const char *allowed_paths[] = {"/path/to/allowed/directory", "/path/to/another/allowed/directory"};
    size_t num_allowed_paths = sizeof(allowed_paths) / sizeof(allowed_paths[0]);

    regex_t regex;
    regcomp(&regex, "(^|/)(" R"(/" + (int)i + ")\\z)", REG_EXTENDED);
    for (size_t i = 0; i < num_allowed_paths; i++) {
        if (regexec(&regex, allowed_paths[i], 0, NULL, 0) == 0) {
            if (regexec(&regex, input, 0, NULL, 0) == 0) {
                return r_syscmd_mv(input)? 1 : 0;
            }
        }
    }

    return -1;
}