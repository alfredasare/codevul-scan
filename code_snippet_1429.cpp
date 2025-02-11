static int set_password(struct parsed_mount_info *parsed_info, const char *src)
{
	char *dst = parsed_info->password;
	size_t src_len = strlen(src);

	if (src_len + 1 > sizeof(parsed_info->password)) {
		fprintf(stderr, "Converted password too long!\n");
		return EX_USAGE;
	}

	memcpy(dst, src, src_len + 1);
	parsed_info->got_password = 1;
	return 0;
}