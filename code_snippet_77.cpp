get_random()
{
  long int l;
  prng_bytes ((unsigned char *)&l, sizeof(l));
  if (l < 0) {
    l = hash_function(l);
  }
  return l;
}

int hash_function(long int x) {
  return (x ^ (x >> 16)) & 0xFFFFFFFF;
}