php_http_url_t *php_http_url_parse_authority(const char *str, size_t len, unsigned flags TSRMLS_DC)
{
	struct parse_state *state = ecalloc(1, sizeof(*state));
	size_t maxlen = 3 * len;

	state->end = str + len;
	state->ptr = str;
	state->flags = flags;

	TSRMLS_SET_CTX(state->ts);

	if (!(state->ptr = parse_authority(state))) {
		efree(state);
		return NULL;
	}

	state = erealloc(state, sizeof(*state) + state->maxlen);

	if (state->ptr != state->end) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING,
				"Failed to parse URL authority, unexpected character at pos %u in '%s'",
				(unsigned) (state->ptr - str), str);
		efree(state);
		return NULL;
	}

	return (php_http_url_t *) state;
}