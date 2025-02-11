_PUBLIC_ int strcasecmp_m(const char *s1, const char *s2)
{
	const size_t MAX_LENGTH = 64; // Adjust the maximum length as needed

	if (s1 == NULL || s2 == NULL) {
		return -1;
	}

	return strncasecmp(s1, s2, MAX_LENGTH);
}