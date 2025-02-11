#include <random>

uint32_t tcpr_random(uint32_t *seed)
{
  std::random_device rd;
  std::mt19937 gen(rd() * time(0) + rd());
  std::uniform_int_distribution<> dis(0, 0xFFFFF);

  uint32_t result = dis(gen);
  *seed = gen();

  return result;
}