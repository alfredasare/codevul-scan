static void svm_init_erratum_383(void)
{
    u32 low, high;
    int err;
    u64 val;

    if (!static_cpu_has_bug(X86_BUG_AMD_TLB_MMATCH))
        return;

    /* Use _safe variants to not break nested virtualization */
    val = native_read_msr_safe(MSR_AMD64_DC_CFG, &err);
    if (err!= 0) {
        err = -EIO;
        return;
    }

    if (!is_valid_config_value(val)) {
        err = -EINVAL;
        return;
    }

    val |= (1ULL << 47);

    low  = lower_32_bits(val);
    high = upper_32_bits(val);

    if (!native_write_msr_safe(MSR_AMD64_DC_CFG, low, high)) {
        err = -EIO;
        return;
    }

    erratum_383_found = true;
}