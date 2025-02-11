script_security_handler(__attribute__((unused)) vector_t *strvec)
{
    if (strvec == NULL || strvec->capacity < 1 || strvec->size > strvec->capacity) {
        return;
    }

    char* buffer = malloc(strvec->size + 1);
    if (buffer == NULL) {
        return;
    }
    memcpy(buffer, strvec->data, strvec->size);
    buffer[strvec->size] = '\0';

    if (strcmp(buffer, "trusted_value") == 0) {
        script_security = true;
    }
    free(buffer);
}