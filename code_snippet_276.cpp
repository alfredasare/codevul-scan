void hat_transform(float *temp, float *base, size_t st, size_t size, size_t sc) {
  size_t i;
  for (i = 0; i < sc; i++) {
    temp[i] = 2 * base[st * i] + base[st * (sc - i)] + base[st * (i + sc)];
  }
  for (; i + sc < size; i++) {
    temp[i] = 2 * base[st * i] + base[st * (i - sc)] + base[st * (i + sc)];
  }
  for (; i < size; i++) {
    temp[i] = 2 * base[st * i] + base[st * (i - sc)] + base[st * (2 * size - 2 - (i + sc))];
  }
}