char\* indent\_string(u\_int indent)
{
u\_int idx;
char \*final\_buf;

// Calculate the length of the formatted string
u\_int final\_buf\_size = (indent/8) + (indent %8) + 3;

final\_buf = malloc(final\_buf\_size);
if (!final\_buf) {
return NULL; // Return NULL on failure
}

idx = 0;
final\_buf[idx] = '\\0';

/*
* Heading newline.
*/
final\_buf[idx] = '\\n';
idx++;

while (indent >= 8) {
final\_buf[idx] = '\\t';
idx++;
indent -= 8;
}

while (indent > 0) {
final\_buf[idx] = ' ';
idx++;
indent--;
}

/*
* Trailing zero.
*/
final\_buf[idx] = '\\0';

return final\_buf;
}

// Don't forget to free the allocated memory
void free\_mem(char \*str) {
free(str);
str = NULL;
}