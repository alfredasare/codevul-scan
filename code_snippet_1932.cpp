#include <stdint.h>

gettime1900d(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL); /* never fails */

        /* Calculate fractional part using a larger data type */
        long long fractional_part = (int64_t)(1.0e-6 * tv.tv_usec);

        /* Check for overflow */
        if ((time_t)(tv.tv_sec + fractional_part/1000000 + OFFSET_1900_1970) < tv.tv_sec) {
                /* Handle error */
                /* ... */
                return -1;
        }

	G.cur_time = tv.tv_sec + fractional_part/1000000 + OFFSET_1900_1970;
	return G.cur_time;
}