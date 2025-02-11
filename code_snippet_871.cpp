static void Sp_toLowerCase(js_State *J)
{
	const char *src = checkstring(J, 0);
	size_t src_len = strlen(src);
	size_t max_dst_len = UTFmax * src_len + 1;
	char *dst = js_malloc(J, max_dst_len);

	const char *s = src;
	char *d = dst;
	Rune rune;
	while (*s && (d - dst) < max_dst_len) {
		s += chartorune(&rune, s);
		rune = tolowerrune(rune);
		d += runetochar(d, &rune);
	}
	*d = 0;
	if (js_try(J)) {
		js_free(J, dst);
		js_throw(J);
	}
	js_pushstring(J, dst);
	js_endtry(J);
	js_free(J, dst);
}