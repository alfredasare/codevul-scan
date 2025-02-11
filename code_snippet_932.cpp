static int __init register_memory(void)
{
    char *safe_text = realpath(_text, NULL);
    char *safe_etext = realpath(_etext, NULL);
    char *safe_edata = realpath(_edata, NULL);
    char *safe_end = realpath(_end, NULL);

    if (safe_text == NULL || safe_etext == NULL || safe_edata == NULL || safe_end == NULL) {
        return -EINVAL; // Handle error
    }

    code_resource.start = ia64_tpa(safe_text);
    code_resource.end = ia64_tpa(safe_etext) - 1;
    data_resource.start = ia64_tpa(safe_etext);
    data_resource.end = ia64_tpa(safe_edata) - 1;
    bss_resource.start = ia64_tpa(__bss_start);
    bss_resource.end = ia64_tpa(safe_end) - 1;

    efi_initialize_iomem_resources(&code_resource, &data_resource, &bss_resource);

    return 0;
}