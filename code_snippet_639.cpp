create_lwfn_name( char*   ps_name,
                  Str255  lwfn_file_name )
{
    int max_len = strlen(ps_name) + 1; // +1 for the null-terminator
    char* sanitized_name = malloc(max_len);
    strcpy(sanitized_name, ps_name);
    sanitized_name[max_len - 1] = '\0'; // Ensure null-termination

    int count = 0;
    FT_Byte* p = lwfn_file_name;
    FT_Byte* q = (FT_Byte*)sanitized_name;

    while (*q) {
        if (ft_isupper(*q)) {
            if (count) {
                max_len = 3;
            }
            count = 0;
        }
        if (count < max_len && (ft_isalnum(*q) || *q == '_')) {
            *++p = *q;
            lwfn_file_name[0]++;
            count++;
        }
        q++;
    }

    free(sanitized_name);
    lwfn_file_name[lwfn_file_name[0]] = '\0';
}