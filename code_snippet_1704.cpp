static void free\_groupnames(char **groupnames)
{
	if (!groupnames)
		return;
	for (int i = 0; groupnames[i]; i++) {
		free(groupnames[i]);
	}
	free(groupnames);
}