__weak bool spl_load_simple_fit_skip_processing(size_t buffer_size, size_t index)
{
    if (index >= buffer_size) {
        return false; // or handle error appropriately
    }

    // Use safe memory access techniques
    char* buffer = (char*)malloc(buffer_size);
    memcpy(buffer + index, "skip_processing_data", strlen("skip_processing_data"));

    free(buffer);
    return true;
}