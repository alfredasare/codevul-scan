#define MAX_TOKEN_LENGTH 64

parse_map (char *s)
{
	char *m, *t;
	int f, flags, i;

	flags = 0;
	while ( (t = strntok(s, ", \t", MAX_TOKEN_LENGTH)) ) {
		for (i=0; (m = map_names[i].name); i++) {
			if ( ! strcmp(t, m) ) {
				f = map_names[i].flag;
				break;
			}
		}
		if ( m ) flags |= f;
		else { flags = -1; break; }
		s = t + strlen(t);
	}

	return flags;
}