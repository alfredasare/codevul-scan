static char *find_field(char *nf, char *of)
{
	if (nf == NULL) {
		fprintf(stderr, "Null pointer error: nf is null\n");
		return NULL;
	}

	if (of == NULL) {
		fprintf(stderr, "Null pointer error: of is null\n");
		return NULL;
	}

	if (nf)
		return nf;
	return of;
}