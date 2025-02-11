SCOPE_LIST* license_new_scope_list()
{
    SCOPE_LIST* scopeList;
    int error;

    scopeList = malloc(sizeof(SCOPE_LIST));
    if (!scopeList) {
        return NULL;
    }

    scopeList->count = 0;
    scopeList->array = NULL;

    return scopeList;
}