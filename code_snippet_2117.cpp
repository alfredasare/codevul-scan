ref_param_end_write_collection(gs_param_list * plist, gs_param_name pkey,
                               gs_param_dict * pvalue)
{
    iparam_list *const iplist = (iparam_list *) plist;
    int code = ref_param_write(iplist, pkey, &((dict_param_list *) pvalue->list)->dict);

    if (code != REF_PARAM_SUCCESS) {
        printf("Error writing parameter: %d\n");
        return code;
    }

    gs_free_object(plist->memory, pvalue->list, "ref_param_end_write_collection");
    pvalue->list = 0;
    return code;
}