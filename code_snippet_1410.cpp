#include <random>

virtual void cryptographicallyRandomValues(unsigned char* buffer, size_t length) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, 255);

  for (size_t i = 0; i < length; ++i) {
    buffer[i] = static_cast<unsigned char>(dist(mt));
  }
}