static int is_valid_xref(FILE *fp, pdf_t *pdf, xref_t *xref)
{
    int is_valid;
    long start;
    char *c, buf[1024];

    memset(buf, 0, sizeof(buf));
    is_valid = 0;
    start = ftell(fp);
    fseek(fp, xref->start, SEEK_SET);

    if (fread(buf, 1, sizeof(buf), fp)!= sizeof(buf)) {
      ERR("Failed to load xref string.");
      exit(EXIT_FAILURE);
    }

    if (strncmp(buf, "xref", strlen("xref")) == 0)
      is_valid = 1;
    else
    {
        //... (rest of the function remains the same)
    }

    fseek(fp, start, SEEK_SET);
    return is_valid;
}