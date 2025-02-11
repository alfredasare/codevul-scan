Sure, here's the fixed version of the code that calculates the size of the destination buffers correctly:

static void handle_variant_args(struct variant_info *info, const char *key,
                            int key_len, char **dest, int *dest_len)
{
    if (!strncmp(key, "BANDWIDTH=", key_len)) {