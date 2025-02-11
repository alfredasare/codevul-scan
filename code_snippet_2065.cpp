static char *timelib_string(Scanner *s)
{
    const int MAX_BUFFER_SIZE = 1024; // adjust this value based on your requirements
    char buffer[MAX_BUFFER_SIZE];

    if (s->cur >= s->tok) {
        memcpy(buffer, s->tok, s->cur - s->tok);
        buffer[s->cur - s->tok] = '\0'; // null-terminate the string
        return buffer;
    } else {
        // handle invalid input scenario
        return NULL;
    }
}