void gf\_sys\_set\_args(ptrdiff\_t argc, const char \*\*argv, size\_t max\_argv\_size, size\_t max\_argv\_entry\_length)
{
#if !defined(__DARWIN__) && !defined(__APPLE__)
if (!gpac\_argc && (argc >= 0) && (argc < max\_argv\_size))
#endif
{
gpac\_argc = (u32) argc;

// Limit the size of the argv array to prevent buffer overflows
for (u32 i = 0; i < gpac\_argc; i++) {
gpac\_argv[i] = argv[i];
size\_t len = gf\_sys\_safe\_strlen(gpac\_argv[i], max\_argv\_entry\_length);
gpac\_argv[i] = realloc(gpac\_argv[i], len + 1);
gpac\_argv[i][len] = '\0';
}
}
}

size\_t gf\_sys\_safe\_strlen(const char \*str, size\_t max\_length) {
size\_t len = 0;
while (str[len] != '\0' && len < max\_length) {
len++;
}
return len;
}