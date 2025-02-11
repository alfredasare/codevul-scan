int yr_re_match(RE* re, const char* target) {
    size_t target_len = strnlen(target, sizeof(target) / sizeof(target[0]));
    return yr_re_exec(re->code, (uint8_t*) target, target_len, re->flags | RE_FLAGS_SCAN, NULL, NULL);
}