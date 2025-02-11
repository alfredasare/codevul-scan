#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SECRET_KEY_ENV_VAR "API_KEY"

static void DefragTrackerPrintStats(void) {
    char* apiKey = getenv(SECRET_KEY_ENV_VAR);
    if (apiKey == NULL) {
        printf("Error: API key not set.\n");
        exit(1);
    }

    printf("API Key: %s\n", apiKey);
}