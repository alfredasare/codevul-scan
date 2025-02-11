void GenerateSecureHash(const base::string16& password,
                         base::span<uint8_t, kSecureHashLen> hash) {
  size_t length = password.length() * 2;
  base::span<uint8_t> buffer(length);
  memset(buffer.data(), 0x00, length); // Zeroize the buffer

  // Generate a cryptographically secure random salt
  auto salt = base::Random::GenerateBytes(kSaltLen);
  // Concatenate the salt with the password
  base::string16 passwordWithSalt = password + std::string(salt.begin(), salt.end());

  // Hash the password using a secure hash function (e.g., SHA-256)
  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, passwordWithSalt.c_str(), passwordWithSalt.length());
  SHA256_Final(hash.data(), &ctx);

  // Store the salt value separately
  base::span<uint8_t> saltBuffer(kSaltLen);
  memcpy(saltBuffer.data(), salt.data(), kSaltLen);
  // Store the salt buffer securely (e.g., in a secure storage system)
}