#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <error.h>

void printwhat_fixed(int n1, int n2)
{
    if (n1 < INT_MIN || n1 > INT_MAX || n2 < INT_MIN || n2 > INT_MAX) {
        error(0, 0, "Error: Input values are outside the bounds of an integer.");
        return;
    }

    const char* message = (n1 == n2) ? "Giving up.\n\n" : "Retrying.\n\n";
    logputs(LOG_VERBOSE, message);
}