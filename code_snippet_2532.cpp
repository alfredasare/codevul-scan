Sure, here's the fixed version of the code:

void free_scope_list(SCOPE_LIST* scopeList)
{
    if (scopeList->array != NULL)
    {
        free(scopeList->array);
    }
    free(scopeList);
}

SCOPE_LIST* license_new_scope_list()
{
    SCOPE_LIST* scopeList;

    scopeList = (SCOPE_LIST*) malloc(sizeof(SCOPE_LIST));
    if (scopeList == NULL)
    {
        // Handle error
    }
    scopeList->count =