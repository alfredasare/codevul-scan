bitset\_or(BitSetRef dest, BitSetRef bs)
{
  int i;
  for (i = 0; i < BITSET\_SIZE && i < bs.size(); i++) { dest[i] |= bs[i]; }
}