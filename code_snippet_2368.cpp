#include <stddef.h> // for size_t
#include <stdbool.h> // for bool
#include <stdint.h> // for uint8_t
#include <ctype.h> // for isxdigit

static inline uint8_t *PopHexPixel(const char *const *hex_digits, size_t pixel, uint8_t *pixels) {
  if (!hex_digits || pixel >= strlen(*hex_digits) || !is_valid_hex_string(hex_digits[pixel])) {
    // Handle error, e.g., return NULL or set error flag
    return NULL;
  }

  const char *hex = hex_digits[pixel];
  *pixels++ = (uint8_t)strtoul(hex, NULL, 16);
  *pixels++ = (uint8_t)strtoul(hex + 2, NULL, 16);
  return pixels;
}

bool is_valid_hex_string(const char *str) {
  if (strlen(str) != 2) return false;
  for (size_t i = 0; i < 2; ++i) {
    if (!isxdigit(str[i])) return false;
  }
  return true;
}