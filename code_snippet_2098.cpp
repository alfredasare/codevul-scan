static inline void dump_stacktrace(void)
{
    void *array[MAX_STACKDEPTH];
    size_t size;
    char buffer[1024]; // Fixed-size buffer
    size_t i;
    FILE *fp = fopen("/dev/stderr", "w"); // Use a file descriptor

    size = backtrace(array, MAX_STACKDEPTH);
    char **strings = backtrace_symbols_fd(array, size, fp);

    fprintf(fp, "\tObtained %zd stack frames.\n", size);

    for (i = 0; i < size; i++)
        fprintf(fp, "\t\t%s\n", strings[i]);

    free(strings);
    fclose(fp);
}