int tcmur_register_handler(struct tcmur_handler *handler)
{
    struct tcmur_handler *h;
    int i;

    // Validate the input subtype
    if (strlen(handler->subtype) > MAX_SUBTYPE_LENGTH ||!isValidSubtype(handler->subtype)) {
        tcmu_err("Invalid subtype: %s\n", handler->subtype);
        return -1;
    }

    for (i = 0; i < darray_size(g_runner_handlers); i++) {
        h = darray_item(g_runner_handlers, i);
        if (!strcmp(h->subtype, handler->subtype)) {
            tcmu_err("Handler %s has already been registered\n", handler->subtype);
            return -1;
        }
    }

    darray_append(g_runner_handlers, handler);
    return 0;
}

bool isValidSubtype(const char *subtype)
{
    return strlen(subtype) <= MAX_SUBTYPE_LENGTH && strcasecmp(subtype, "valid_subtype") == 0;
}