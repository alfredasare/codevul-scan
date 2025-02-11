void php_gd_error_method(int type, const char *format, va_list args)
{
    TSRMLS_FETCH();

    int buffer_size = 1024; // Define the buffer size
    const char *buffer = malloc(buffer_size); // Allocate memory for the buffer
    int length = vsnprintf(NULL, 0, format, args); // Get the length of the input data
    if (length > buffer_size) {
        free(buffer);
        return; // Return an error or take alternative action
    }

    // Copy the data from the input to the buffer
    vsnprintf(buffer, buffer_size, format, args);

    free(buffer);
}