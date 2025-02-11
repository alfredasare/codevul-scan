static void jsP_next(js_State *J)
{
    jsToken token = jsY_lex(J);
    if (token == NULL) {
        return;
    }
    J->lookahead = token;
    J->astline = J->lexline;
}