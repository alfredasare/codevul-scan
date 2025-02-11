#include <stdint.h>

int32_t le4_safe(const unsigned char *p)
{
	uint64_t val = ((uint64_t)p[0] << 16) + (((uint64_t)p[1]) << 24) + (p[2] << 0) + (p[3] << 8);
	if (val > INT32_MAX || val < INT32_MIN) {
		// Handle error condition
		return INT32_MIN;
	}
	return (int32_t)val;
}