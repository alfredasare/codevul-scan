init_mime( void )
{
    int i;

    /* Sort the tables so we can do binary search. */
    qsort( enc_tab, n_enc_tab, sizeof(*enc_tab), ext_compare );
    qsort( typ_tab, n_typ_tab, sizeof(*typ_tab), ext_compare );

    /* Fill in the lengths. */
    for ( i = 0; i < n_enc_tab; ++i )
    {
        const char * sanitized_ext = sanitize_input(enc_tab[i].ext);
        enc_tab[i].ext_len = strlen(sanitized_ext);
        const char * sanitized_val = sanitize_input(enc_tab[i].val);
        enc_tab[i].val_len = strlen(sanitized_val);
    }
    for ( i = 0; i < n_typ_tab; ++i )
    {
        const char * sanitized_ext = sanitize_input(typ_tab[i].ext);
        typ_tab[i].ext_len = strlen(sanitized_ext);
        const char * sanitized_val = sanitize_input(typ_tab[i].val);
        typ_tab[i].val_len = strlen(sanitized_val);
    }
}

static const char * invalid_chars = "/\\";
const char * sanitize_input(const char * input)
{
    char * sanitized = malloc(strlen(input) + 1);
    char * p = sanitized;
    for (const char * q = input; *q!= '\0'; q++)
    {
        if (strchr(invalid_chars, *q) == NULL)
        {
            *p++ = *q;
        }
    }
    *p = '\0';
    return sanitized;
}