static bool isUninitializedMemory(void\* objectPointer, size_t objectSize) {
return std::all\_of(static\_cast<char\*>(objectPointer), static\_cast<char\*>(objectPointer) + objectSize,
[](unsigned char c) { return c == 0; });
}