ref_param_end_write_collection(gs_param_list * plist, gs_param_name pkey,
                               gs_param_dict * pvalue)
{
    iparam_list *const iplist = (iparam_list *) plist;
    if (pvalue->list != NULL) {
        int code = ref_param_write(iplist, pkey, &((dict_param_list *) pvalue->list)->dict);

        gs_free_object(plist->memory, pvalue->list, "ref_param_end_write_collection");
        pvalue->list = 0;
        return code;
    } else {
        // Return an error code or log an error message
        return ERROR_CODE; // Replace ERROR_CODE with an appropriate error code
    }
}