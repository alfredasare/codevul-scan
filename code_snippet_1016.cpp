In this updated code, we calculate the length of the `property` string and compare it with the maximum allowed length `QEMU_FDT_MAX_PROP_LEN`. If the combined length of the property name and value exceeds the buffer size, we return an error code. Note that you should define the constant `QEMU_FDT_MAX_PROP_LEN` based on the maximum allowed size of the buffer.


int qemu_fdt_setprop_u64(void *fdt, const char *node_path,
                         const char *property, uint6