#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void print_var_str(const char *var, const char *val)
{
    char buffer[1024];
    int buffer_len = sizeof(buffer) / sizeof(buffer[0]);
    snprintf(buffer, buffer_len, "%s='%s'\n", var, val);
    printf("%s", buffer);
}