static char *timelib_string_fixed(Scanner *s)
{
	if (s->cur - s->tok >= INT_MAX - 1) {
		// Handle error
	}

	char *tmp = calloc(1, s->cur - s->tok + 1);
	strncpy(tmp, s->tok, s->cur - s->tok);

	return tmp;
}