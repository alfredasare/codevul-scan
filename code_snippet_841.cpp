#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XML_PASSWORD_ENV "XML_PASSWORD"

int main() {
    const char *password = getenv(XML_PASSWORD_ENV);
    if (password == NULL) {
        fprintf(stderr, "Error: XML_PASSWORD_ENV not set\n");
        exit(1);
    }
    xmlParseEntity(NULL, password);

    return 0;
}