int ismode(const char *start, const char *end, int *permset)
{
	const char *p;
	size_t len = end - start;

	if (len > ARCHIVE_ENTRY_acl_perm_MAX || start >= end)
		return (0);
	p = start;
	*permset = 0;
	while (p < end) {
		switch (*p++) {
		case 'r': case 'R':
			if (strncmp(p, "read", 4) != 0)
				return (0);
			*permset |= ARCHIVE_ENTRY_ACL_READ;
			p += 4;
			break;
		case 'w': case 'W':
			if (strncmp(p, "write", 5) != 0)
				return (0);
			*permset |= ARCHIVE_ENTRY_ACL_WRITE;
			p += 5;
			break;
		case 'x': case 'X':
			if (strncmp(p, "exec", 4) != 0)
				return (0);
			*permset |= ARCHIVE_ENTRY_ACL_EXECUTE;
			p += 4;
			break;
		case '-':
			p++;
			break;
		default:
			return (0);
		}
	}
	return (1);
}