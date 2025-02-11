htmlReadFile(const char *filename, const char *encoding, int options)
{
    htmlParserCtxtPtr ctxt;
    size_t filename_len = strlen(filename);
    const size_t MAX_FILENAME_LENGTH = 256; // Define the maximum allowed length

    // Allocate memory for the filename parameter
    char *filename_ptr = malloc(filename_len + 1);

    // Copy the filename string into the allocated memory
    strcpy(filename_ptr, filename);

    // Validate the filename length
    if (filename_len >= MAX_FILENAME_LENGTH) {
        // Handle error or truncate the filename
        filename_len = MAX_FILENAME_LENGTH - 1;
        filename_ptr[filename_len] = '\0';
    }

    xmlInitParser();
    ctxt = htmlCreateFileParserCtxt(filename_ptr, encoding);
    if (ctxt == NULL)
        return (NULL);
    free(filename_ptr); // Free allocated memory
    return (htmlDoRead(ctxt, NULL, NULL, options, 0));
}