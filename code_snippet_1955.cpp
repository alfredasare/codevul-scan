static pdf_creator_t *new_creator(int *n_elements)
{
    pdf_creator_t *daddy;
    size_t template_size = sizeof(creator_template);

    static const pdf_creator_t creator_template[] = 
    {
        {"Title",        ""},
        {"Author",       ""},
        {"Subject",      ""},
        {"Keywords",     ""},
        {"Creator",      ""},
        {"Producer",     ""},
        {"CreationDate", ""},