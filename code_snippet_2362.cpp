#define MAX_INPUT_LENGTH 1024

int yr_re_match(RE* re, const char* target)
{
    if (strlen(target) > MAX_INPUT_LENGTH) {
        return YR_ERROR_INVALID_INPUT;
    }

    return yr_re_exec(re->code, (uint8_t*)target, MAX_INPUT_LENGTH, re->flags | RE_FLAGS_SCAN, NULL, NULL);
}