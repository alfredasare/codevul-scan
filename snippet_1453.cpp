static const char *parse_fragment(struct parse_state *state)
{
	size_t mb;
	const char *tmp;
	TSRMLS_FETCH_FROM_CTX(state->ts);

	/* is there actually a fragment to parse? */
	if (*state->ptr != '#') {
		return state->ptr;
	}

	/* skip initial '#' */
	tmp = ++state->ptr;
	state->url.fragment = &state->buffer[state->offset];

	do {
		switch (*state->ptr) {
		case '%':
			if (state->ptr[1] != '%' && (state->end - state->ptr <= 2 || !isxdigit(*(state->ptr+1)) || !isxdigit(*(state->ptr+2)))) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING,
						"Failed to parse fragment; invalid percent encoding at pos %u in '%s'",
						(unsigned) (state->ptr - tmp), tmp);
				return NULL;
			}
			state->buffer[state->offset++] = *state->ptr++;
			state->buffer[state->offset++] = *state->ptr++;
			state->buffer[state->offset++] = *state->ptr;
			break;

		/* RFC1738 unsafe */
		case '{': case '}':
		case '<': case '>':
		case '[': case ']':
		case '|': case '\\': case '^': case '`': case '"': case ' ':
			if (state->flags & PHP_HTTP_URL_PARSE_TOPCT) {
				state->buffer[state->offset++] = '%';
				state->buffer[state->offset++] = parse_xdigits[((unsigned char) *state->ptr) >> 4];
				state->buffer[state->offset++] = parse_xdigits[((unsigned char) *state->ptr) & 0xf];
				break;
			}
			/* no break */

		case '?': case '/':
		case '!': case '$': case '&': case '\'': case '(': case ')': case '*':
		case '+': case ',': case ';': case '=': /* sub-delims */
		case '-': case '.': case '_': case '~': /* unreserved */
		case ':': case '@': /* pchar */
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
		case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
		case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
		case 'V': case 'W': case 'X': case 'Y': case 'Z':
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
		case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
		case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
		case 'v': case 'w': case 'x': case 'y': case 'z':
		case '0': case '1': case '2': case '3': case '4': case '5': case '6':
		case '7': case '8': case '9':
			/* allowed */
			state->buffer[state->offset++] = *state->ptr;
			break;

		default:
			if (!(mb = parse_mb(state, PARSE_FRAGMENT, state->ptr, state->end, tmp, 0))) {
				return NULL;
			}
			state->ptr += mb - 1;
		}
	} while (++state->ptr < state->end);

	state->buffer[state->offset++] = 0;
	return state->ptr;
}
