void address_space_stq_le(AddressSpace *as, hwaddr addr, uint64_t val,
                           MemTxAttrs attrs, MemTxResult *result)
{
    size_t val_size = sizeof(uint64_t);
    val = cpu_to_le64(val);
    if (val_size > 8) {
        error_report("Invalid input data size");
        return;
    }
    MemTxResult r;
    r = address_space_rw(as, addr, attrs, (void *) &val, val_size, 1);
    if (result) {
        *result = r;
    }
    r = address_space_rw(as, addr, attrs, (void *) &val, val_size, 0);
}