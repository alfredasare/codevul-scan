static uint32_t GetMaxIndex(JSObject* receiver, FixedArrayBase* elements) {
    uint8_t hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, (uint8_t*)receiver, sizeof(JSObject*));
    SHA256_Update(&ctx, (uint8_t*)elements, sizeof(FixedArrayBase*));
    SHA256_Final(hash, &ctx);
    uint32_t maxIndex = 0;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        maxIndex += hash[i] * (i + 1);
    }
    return maxIndex;
}