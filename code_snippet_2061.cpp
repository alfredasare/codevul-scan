#include <string.h>
#include "errmsg.h"

#define MAX_NAME_LENGTH 64 // adjust the maximum length as needed

typedef struct {
    const char* name;
    int type;
} socket_type;

static socket_type socketTypes[] = {
    {"type1", 1},
    {"type2", 2},
    /* ... */
};

static int getSocketType(char* name) {
    int type = -1;
    size_t i;

    /* Check if input name is within buffer limit */
    if (strlen(name) >= MAX_NAME_LENGTH) {
        errmsg.LogError(0, NO_ERRCODE, "Input name exceeds maximum length");
        return type;
    }

    /* match name with known socket type */
    for(i=0; i<sizeof(socketTypes)/sizeof(socket_type); ++i) {
        if( !strcmp(socketTypes[i].name, name) ) {
            type = socketTypes[i].type;
            break;
        }
    }

    /* whine if no match was found. */
    if (type == -1) 
        errmsg.LogError(0, NO_ERRCODE, "unknown type %s", name);

    return type;
}