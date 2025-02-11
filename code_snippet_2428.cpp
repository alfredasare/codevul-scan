NO_INLINE void jsError\_flash(const char \*fmt, ...) {
va\_list argp;
va\_start(argp, fmt);

// Calculate the required buffer size
size\_t len = vsnprintf(NULL, 0, fmt, argp);
va\_end(argp);

// Allocate the buffer on the heap to accommodate the longest possible string
char \*buff = malloc(len + 1);
if (!buff) {
// Handle allocation failure appropriately, e.g., return or propagate error
}

va\_start(argp, fmt);
vsnprintf(buff, len + 1, fmt, argp);
va\_end(argp);

jsiConsoleRemoveInputLine();
jsiConsolePrint("ERROR: ");
jsiConsolePrintString(buff);
jsiConsolePrint("\n");

// Free the allocated buffer after usage
free(buff);
}