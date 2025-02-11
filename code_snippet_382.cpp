compute_nhash (uschar *subject, int value1, int value2, uschar **output_str, int *len)
{
uschar *s = subject;
int i = 0;
unsigned long int total = 0; /* no overflow */
size_t bufsize = 32; // adjusted size for the worst-case scenario
uschar *buf = malloc(bufsize);

*output_str = buf;

if (!buf) {
// error handling for out-of-memory situation
return -1;
}

while (*s != 0)
{
if (i == 0) i = sizeof(prime)/sizeof(int) - 1;
total += prime[i--] * (unsigned int)(*s++);
}

// Adjusted the division to happen before the modulo operation
// This avoids the division by zero when value2 is zero

if (value2 != 0) {
total %= (value1 * value2);
} else {
// error handling for value2 being zero
return -1;
}

bufsize = snprintf(buf, bufsize, "%d/%d", total/value2, total % value2) + 1;

// Reallocating the buffer with the correct size
buf = realloc(buf, bufsize);

if (!buf) {
// error handling for out-of-memory situation
return -1;
}

snprintf(buf, bufsize, "%d/%d", total/value2, total % value2);
*len = (int)strlen(buf);
return 0;
}