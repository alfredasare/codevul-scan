GF\_Err styl\_dump(GF\_Box *a, FILE * trace)
{
    u32 i;
    GF\_TextStyleBox\*p = NULL;
    if(!a || !trace)
        return GF\_BAD\_PARAM;
    p = (GF\_TextStyleBox\*)a;
    gf\_isom\_box\_dump\_start(a, "TextStyleBox", trace);
    fprintf(trace, ">\n");
    for (i=0; i<p->entry\_count; i++) tx3g\_dump\_style(trace, &p->styles[i]);
    if (!p->size) {
        fprintf(trace, "<StyleRecord startChar=\"\" endChar=\"\" fontID=\"\" styles=\"Normal|Bold|Italic|Underlined\" fontSize=\"\" textColor=\"\" />\n");
    }
    gf\_isom\_box\_dump\_done("TextStyleBox", a, trace);
    return GF\_OK;
}