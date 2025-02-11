#include <stdlib.h>

// Hypothetical memory allocation function
void *ppmd_alloc(size_t size);

// Fixed version of the vulnerable ppmd_free function
void ppmd_free(void **p, void *address) {
    if (!p || !address || *p != address) {
        // Invalid pointer or already freed, do not free
        return;
    }

    // Use a bookkeeping system to ensure the memory address is not freed twice
    if (!is_memory_address_freed(address)) {
        free(address);
        mark_memory_address_as_freed(address);
        *p = NULL;
    }
}