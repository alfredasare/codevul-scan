#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <ctype.h>

bool xps_parse_real_num(const char *str, float *value) {
    // Implement a proper real number parsing function with error handling
    // Return true if successful, false otherwise
}

xps_parse_glyph_offsets(char *s, float *uofs, float *vofs) {
    bool offsets_overridden; /* not used */

    if (s == NULL || uofs == NULL || vofs == NULL) {
        // Return early if any of the pointers are NULL
        return s;