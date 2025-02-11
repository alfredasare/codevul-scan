char* indent_string(u_int indent) {
    const int BUFFER_SIZE = 20;
    char* buf = malloc(BUFFER_SIZE);

    int idx = 0;
    buf[idx] = '\0'; // Initialize the buffer with a null terminator

    if (indent > BUFFER_SIZE) {
        // Handle the case where the indent value exceeds the buffer size
        return NULL; // or handle it in a different way according to your requirements
    }

    buf[idx] = '\n';
    idx++;

    while (indent >= 8) {
        buf[idx] = '\t';
        idx++;
        indent -= 8;
    }

    while (indent > 0) {
        buf[idx] ='';
        idx++;
        indent--;
    }

    buf[idx] = '\0'; // Add the null terminator

    char* result = malloc(idx + 1); // Create a new buffer for the result
    memcpy(result, buf, idx); // Copy the contents of the original buffer to the result buffer
    free(buf); // Free the original buffer
    return result;
}