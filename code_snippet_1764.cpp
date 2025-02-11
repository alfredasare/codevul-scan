static bool get_new_nicname(char **dest, const char *br, int pid, char **cnic)
{
	char template[IFNAMSIZ];
	const char *safe_template = "veth%06x";

	sprintf_s(template, sizeof(template), safe_template, arc4random());
	*dest = strdup(template);

	if (!create_nic(*dest, br, pid, cnic)) {
		free(*dest);
		*dest = NULL;
		return false;
	}
	return true;
}