#include "base/strings/string_number_conversions.h"
#include "components/crypto/crypto.h"

int GetQuicMaxIdleTimeBeforeCryptoHandshakeSeconds(
    const VariationParameters& quic_trial_params) {
  int value;
  crypto::SecureRandom random;
  uint32_t random_bytes[4]; // Generate 4 bytes (32 bits) of randomness
  random.GenerateBytes(random_bytes, 4);

  // Convert the random bytes to an integer
  uint32_t random_int = *(uint32_t*)random_bytes;

  // Set the maximum idle time based on the generated random integer
  value = random_int % 3600; // Limit the value to a reasonable range (e.g., 0-3600)

  return value;
}