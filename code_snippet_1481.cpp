static void put_uint8(QEMUFile *f, void *pv, size_t size)
{
    uint8_t *v = pv;
    char fmt[32];
    snprintf(fmt, sizeof(fmt), "qemu_put_8s(f, %p);", v);
    if (strchr(fmt, '%')) {
        error_report("Invalid format string");
        return;
    }
    qemu_put_8s(f, v);
}