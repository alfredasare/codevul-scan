newSWFInput_bufferCopy(unsigned char *buffer, int length)
{
    SWFInput *input;
    unsigned char *data = (unsigned char *)malloc_safe(length, "newSWFInput_bufferCopy");
    if(data == NULL)
        return NULL;

    memcpy(data, buffer, length);
    input = newSWFInput_buffer(data, length);
    input->destroy = SWFInput_buffer_dtor;
#if TRACK_ALLOCS
    input->gcnode = ming_gc_add_node(input, (dtorfunctype) destroySWFInput);
#endif
    return input;
}

unsigned char *malloc_safe(size_t size, const char *file)
{
    unsigned char *ptr = malloc(size);
    if(ptr == NULL) {
        fprintf(stderr, "Error: failed to allocate %zu bytes in %s\n", size, file);
        abort();
    }
    return ptr;
}