newSWFInput_bufferCopy(unsigned char *buffer, int length)
{
    SWFInput input;
    unsigned char *data = (unsigned char *)realloc(input->data, input->size + length);
    if(data == NULL)
        return NULL;

    if (length > 0 && (input->size - input->pos) < length) {
        // Error handling: return NULL, free the memory, or throw an exception
    }

    memmove(&data[input->pos + input->size], buffer, length);
    input->size += length;
    input->data = data;
    input->pos += input->size - length;
    input->destroy = SWFInput_buffer_dtor;

#if TRACK_ALLOCS
    input->gcnode = ming_gc_add_node(input, (dtorfunctype) destroySWFInput);
#endif

    return input;
}