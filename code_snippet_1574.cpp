static int toIntType(char *key, char *type) {
    if (strncmp(type, "string", 6) == 0) {
        return TYPE_STRING;
    } else if (strncmp(type, "list", 4) == 0) {
        return TYPE_LIST;
    } else if (strncmp(type, "set", 3) == 0) {
        return TYPE_SET;
    } else if (strncmp(type, "hash", 4) == 0) {
        return TYPE_HASH;
    } else if (strncmp(type, "zset", 4) == 0) {
        return TYPE_ZSET;
    } else if (strncmp(type, "none", 4) == 0) {
        return TYPE_NONE;
    } else {
        fprintf(stderr, "Unknown type '%s' for key '%s'\n", type, key);
        exit(1);
    }
}