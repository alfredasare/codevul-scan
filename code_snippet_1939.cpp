#include <string.h>
#include <stdio.h>

int unaligned_memcmp(const void *p, const void *q, size_t l) {
    char *p_str = (char *)p;
    char *q_str = (char *)q;

    // Validate and sanitize the input parameters
    if (strchr(p_str, '/') || strchr(q_str, '/')) {
        printf("Invalid input: Path traversal detected\n");
        return -1;
    }

    // Use a secure memory allocation function
    char *aligned_p = (char *)calloc(l + 1, 1);
    char *aligned_q = (char *)calloc(l + 1, 1);

    // Copy the input data to the allocated memory
    memcpy(aligned_p, p_str, l);
    memcpy(aligned_q, q_str, l);

    // Perform the comparison
    int result = memcmp(aligned_p, aligned_q, l);

    // Free the allocated memory
    free(aligned_p);
    free(aligned_q);

    return result;
}