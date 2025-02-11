static inline void dump\_stacktrace(void)
{
void \*\*strings = NULL;
size\_t size;

size = backtrace(strings, MAX\_STACKDEPTH);
strings = backtrace\_symbols(strings, size);

fprintf(stderr, "\tObtained %zd stack frames.\n", size);

for (size\_t i = 0; i < size; i++)
fprintf(stderr, "\t\t%s\n", strings[i]);

free (strings);
}