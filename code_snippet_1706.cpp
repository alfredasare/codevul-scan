SRP_gN *SRP_get_default_gN(const char *id)
{
	size_t i;

	if (id == NULL) 
		return knowngN;
	for(i = 0; i < KNOWN_GN_NUMBER; i++)
	{
		if (strncmp(knowngN[i].id, id, sizeof(knowngN[i].id)) == 0)
		{
			return knowngN + i;
		}
	}
	return NULL;
}