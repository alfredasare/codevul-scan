#include <string.h>
#include <stdio.h>

#define MAX_TYPE_LEN 16

static int toIntType(char *key, char *type) {
    type[MAX_TYPE_LEN - 1] = '\0';

    if(!strcmp(type, "string")) {
        return TYPE_STRING;
    } else if(!strcmp(type, "list")) {
        return TYPE_LIST;