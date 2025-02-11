ref_param_write_typed_array(gs_param_list * plist, gs_param_name pkey,
                            ref *pvalue, uint count,
                            int (*make)(ref *, const void *, uint, gs_ref_memory_t *))
{
    //...
    for (i = 0, pe = value.value.refs; i < count; ++i, ++pe)
        if ((code = (*make) (pe, pvalue, i, iplist->ref_memory)) < 0)
            return code;
    //...
}