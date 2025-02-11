static void jsP_next(js_State *J)
{
	if (J->lookahead != NULL) {
		J->astline = J->lexline;
		J->lookahead = jsY_lex(J);
	}
}