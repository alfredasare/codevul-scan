#include <openssl/rand.h>

init_cell_pool(void)
{
  tor_assert(!cell_pool);
  unsigned char buffer[16];
  if (RAND_bytes(buffer, 16)!= 1) {
    // Handle error
  }
  cell_pool = mp_pool_new(sizeof(packed_cell_t), 128*1024);
  mp_pool_init(cell_pool, buffer, 16);
}