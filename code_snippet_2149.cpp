void _not_implemented(const char *what) {
    char buffer[256]; 
    snprintf(buffer, sizeof(buffer), "Not implemented: %s", what);
    fprint_str(stderr, buffer);
    _exit(42);
}