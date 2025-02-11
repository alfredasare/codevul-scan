ref_param_write_typed_array(gs_param_list * plist, gs_param_name pkey,
void *pvalue, uint count, size_t element_size,
int (*make)(ref *, const void *, uint,
gs_ref_memory_t *))
{
iparam_list *const iplist = (iparam_list *) plist;
ref value;
uint i;
ref *pe;
int code;
size_t max_index = count - 1;

if ((code = ref_array_param_requested(iplist, pkey, &value, count,
"ref_param_write_typed_array")) <= 0)
return code;

// Validate pvalue and its size
if (pvalue == NULL || count > (UINT_MAX / element_size)) {
return -1;
}

for (i = 0, pe = value.value.refs; i < count; ++i, ++pe) {
// Implement bounds checking for the index
if (i > max_index) {
return -1;
}

if ((code = (*make) (pe, ((char *)pvalue + i * element_size), i, iplist->
ref_memory)) < 0)
return code;
}
return ref_param_write(iplist, pkey, &value);
}