bitset_or(BitSetRef dest, BitSetRef bs)
{
  if (!dest || !bs) {
    printf("Error: Invalid input pointers\n");
    return;
  }

  int i;
  for (i = 0; i < BITSET_SIZE; i++) {
    dest[i] |= bs[i];
  }
}