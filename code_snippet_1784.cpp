int yr_arena_write_string(YR_ARENA* arena, const char* string, char* written_string, size_t max_chars)
{
    if (max_chars > 0 && strlen(string) >= max_chars) {
        // Handle error: input string is larger than the destination buffer
        return -1;
    }

    strncpy(written_string, string, max_chars);
    written_string[max_chars - 1] = '\0';

    return 0;
}