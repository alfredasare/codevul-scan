#include <stdint.h>

static inline uint8_t ClampYCC(double value)
{
    value = 255.0 - value;
    if (value < 0.0) return 0;
    if (value > 255.0) return 255;
    return (uint8_t)value;
}