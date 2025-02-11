#include <stdint.h>
#if HAVE_ARC4RANDOM_UNIFORM
#include <stdlib.h>

get_random()
{
  return arc4random_uniform(LLONG_MAX);
}

#else
// Fallback implementation using OpenSSL
#include <openssl/rand.h>

get_random()
{
  uint64_t r;
  RAND_bytes((unsigned char *)&r, sizeof(r));
  if (r > 0) return r;
  else return -r;
}
#endif