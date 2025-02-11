#include <cstdlib>

void MockGenerateRandom1(uint8_t* output, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    output[i] = static_cast<uint8_t>(rand());
  }
}