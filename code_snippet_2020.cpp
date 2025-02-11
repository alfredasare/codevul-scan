char *curl_unescape(const char *string, int length)
{
    const int MAX_LENGTH = 1024;
    int actual_length = (length > MAX_LENGTH)? MAX_LENGTH : length;
    char *unescaped_string = (char *)malloc(actual_length + 1);
    if (!unescaped_string) {
        return NULL;
    }
    for (int i = 0; i < actual_length; i++) {
        if (string[i] == '\0' || string[i] == '%') {
            break;
        }
        unescaped_string[i] = string[i];
    }
    unescaped_string[actual_length] = '\0';
    char *result = curl_easy_unescape(NULL, unescaped_string, actual_length, NULL);
    free(unescaped_string);
    return result;
}