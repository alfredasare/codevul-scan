static void Sp_toLowerCase(js_State *J)
{
    const char *src = checkstring(J, 0);
    char *dst = js_malloc(J, UTFmax * strlen(src) + 1);
    const char *s = src;
    char *d = dst;
    UChar* pDest = d;
    while (*s) {
        s += chartorune(&rune, s);
        u_strToLower(J, NULL, &pDest, &rune, 1);
        d = pDest;
    }
    *d = 0;
    //... rest of the code...
}