static __always_inline void __vmcs_writel(unsigned long field, unsigned long value)
{
    uint32_t error;

    asm volatile (__ex(ASM_VMX_VMWRITE_RAX_RDX) "; setna %0"
                   : "=r"(error) : "a"(value), "d"(field) : "cc");

    if (unlikely(error))
        vmwrite_error(field, value);
}