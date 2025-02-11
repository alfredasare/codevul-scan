static __always_inline long vmcs_readl(long field)
{
    if (field < 0 || field > LONG_MAX) {
        return 0; // or throw an error, depending on the requirements
    }
    vmcs_checkl(field);
    return __vmcs_readl(field);
}