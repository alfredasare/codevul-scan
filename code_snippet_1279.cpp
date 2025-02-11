static int set_password(struct parsed_mount_info *parsed_info, const char *src)
{
    char *dst = parsed_info->password;
    unsigned int i = 0, j = 0;
    size_t src_len = strlen(src);

    if (src_len > sizeof(parsed_info->password) - 1) {
        fprintf(stderr, "Converted password too long!\n");
        return EX_USAGE;
    }

    strcpy_s(dst, sizeof(parsed_info->password), src);

    dst[sizeof(parsed_info->password) - 1] = '\0';
    parsed_info->got_password = 1;
    return 0;
}