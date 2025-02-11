size_t SRP_get_default_gN(const char *id)
{
    size_t i;

    if (id == NULL || strlen(id) >= KNOWN_GN_ID_MAX_LENGTH) {
        return NULL; // invalid input
    }

    for(i = 0; i < KNOWN_GN_NUMBER; i++) {
        if (strncasecmp(knowngN[i].id, id, KNOWN_GN_ID_MAX_LENGTH) == 0) {
            return knowngN + i;
        }
    }

    return NULL;
}