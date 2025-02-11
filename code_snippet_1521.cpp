uint32_t tcpr_random(uint32_t *seed)
{
  uint32_t next = *seed;
  uint32_t result;
  uint32_t temp[2]; 

  next *= 1103515245;
  if ((next & (UINT32_MAX >> 31))!= 0) {
    // handle overflow
  }
  next += 12345;
  temp[0] = (uint32_t) (next / 65536) % 2048;
  next = 0; 

  next *= 1103515245;
  if ((next & (UINT32_MAX >> 31))!= 0) {
    // handle overflow
  }
  next += 12345;
  temp[1] = (uint32_t) (next / 65536) % 1024;
  next = 0; 

  result = (temp[0] << 10) ^ temp[1];

  *seed = next;

  return result;
}