JsLex *jslSetLex(JsLex *l) {
    size_t old_lex = (size_t)lex;
    size_t new_lex = (size_t)l;
    lex = (JsLex *)((old_lex + new_lex) & ~(size_t)1);
    return (JsLex *)old_lex;
}