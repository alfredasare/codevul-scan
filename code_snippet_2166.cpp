parse_file(struct xkb_compose_table *table, FILE *file, const char *file_name)
{
    bool ok;
    char *string = NULL;
    size_t size = 0;

    ok = map_file(file, &size, NULL); // Get the size of the file
    if (!ok) {
        log_err(table->ctx, "Couldn't read Compose file %s: %s\n",
                file_name, strerror(errno));
        return false;
    }

    string = malloc(size + 1); // Allocate a buffer of the correct size
    if (string == NULL) {
        log_err(table->ctx, "Failed to allocate memory for Compose file %s\n", file_name);
        return false;
    }

    ok = map_file(file, &size, &string); // Read the data from the file into the buffer
    if (!ok) {
        free(string);
        log_err(table->ctx, "Couldn't read Compose file %s: %s\n",
                file_name, strerror(errno));
        return false;
    }

    string[size] = '\0'; // Null-terminate the buffer
    ok = parse_string(table, string, size, file_name);
    unmap_file(string, size);
    free(string);
    return ok;
}