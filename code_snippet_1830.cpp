static bool isFunctionFlag(const char *n) {
    if (n == NULL || strlen(n) < 5) {
        return false; // invalid input
    }

    return (strncmp (n, "sym.func.", 9) == 0
        || strncmp (n, "method.", 7) == 0
        || strncmp (n, "sym.", 4) == 0
        || strncmp (n, "func.", 5) == 0
        || strncmp (n, "fcn.", 4) == 0);
}