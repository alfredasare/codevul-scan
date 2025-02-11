fixed code:

`#include <stdint.h>`

`#define ULONG_BIT_SIZE (8 * sizeof(uint64_t))`

`bshift(uint64_t* b)`

`{`

 `uint64_t c;`

 `int i;`

 `c = b[3] & 1;`

 `for (i = 3; i > 0; i--)`

 `{`

 `if (ULONG_BIT_SIZE - __builtin_clzl(b[i]) < 1)`

 `return c;`

 `b[i] = (b[i] >> 1) | (b[i - 1] << 31);`

 `}`

 `if (ULONG_BIT_SIZE - __builtin_clzl(b[i]) < 1)`

 `return c;`

 `b[i] >>= 1;`

 `return c;`

`}`