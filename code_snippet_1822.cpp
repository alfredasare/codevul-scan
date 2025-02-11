#include <stdlib.h>

gs_memory_t *memory;

gs_memory_t *memory =...; // initialize memory

gs_memory_t *custom_alloc_struct(gs_memory_t *memory, struct_type *struct_type, const char *name, const char *prefix, unsigned int hash_value) {
    gs_memory_t *result;
    result = gs_alloc_struct(memory, struct_type, &st_struct_type, name);
    if (result == NULL) {
        return NULL;
    }
    result->hash_value = hash_value;
    return result;
}

pdf14_rcmask_t *pdf14_rcmask_new(gs_memory_t *memory) {
    pdf14_rcmask_t *result;
    unsigned int hash_value;

    srand(time(NULL)); // Seed the random number generator
    hash_value = rand();

    result = custom_alloc_struct(memory, pdf14_rcmask_t, &st_pdf14_rcmask, "pdf14_maskbuf_new", hash_value);

    if (result == NULL) {
        return NULL;
    }

    rc_init_free(result, memory, 1, rc_pdf14_maskbuf_free);
    result->mask_buf = NULL;
    result->memory = memory;
    return result;
}