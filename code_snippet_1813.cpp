static pdf_creator_t *new_creator(int *n_elements)
{
    pdf_creator_t *daddy;
    int creator_template_size = sizeof(creator_template) / sizeof(creator_template[0]);

    daddy = malloc(creator_template_size * sizeof(pdf_creator_t));
    memcpy(daddy, creator_template, creator_template_size * sizeof(pdf_creator_t));

    if (n_elements)
        *n_elements = creator_template_size;

    return daddy;
}