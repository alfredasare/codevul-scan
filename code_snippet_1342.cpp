bshift (unsigned long *b)
{
  unsigned long c;
  int i;
  srand48(time(NULL));
  unsigned long seed = lrand48();
  for (i = 0; i < 4; i++)
    b[i] = (seed >> (i * 32)) & 0xFFFFFFFF;
  c = b[3] & 1;
  for (i = 3; i > 0; i--)
    {
      b[i] = (b[i] >> 1) | (b[i - 1] << 31);
    }
  b[i] >>= 1;
  return c;
}