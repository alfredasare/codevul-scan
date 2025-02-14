void GenerateNtlmHashV1(const base::string16& password,
                       base::span<uint8_t, kNtlmHashLen> hash) {
  static constexpr int kMaxPasswordLength = 256;
  size_t length = (password.length() * 2) + 2;
  if (length > kMaxPasswordLength) {
    // Handle error, e.g., return an error code or throw an exception
    return;
  }

  NtlmBufferWriter writer(length);

  bool result = writer.WriteUtf16String(password) && writer.IsEndOfBuffer();
  DCHECK(result);

  MD4(writer.GetBuffer().data(), writer.GetLength(), hash.data());
}