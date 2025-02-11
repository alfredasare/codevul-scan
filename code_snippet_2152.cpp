#include <string.h>
#include <stdio.h>

static char *find_field(char *nf, char *of)
{
    if (!nf && !of) {
        return xstrdup("");
    }

    if (strchr(nf, '<') || strchr(nf, '>')) {
        printf("Invalid character in nf\n");
        return NULL;
    }
    if (strchr(of, '<') || strchr(of, '>')) {
        printf("Invalid character in of\n");
        return NULL;
    }

    char *result = NULL;
    if (nf) {
        result = xstrdup(nf);
    } else {
        result = xstrdup(of);
    }

    return result;
}