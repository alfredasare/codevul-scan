static void put_uint8(QEMUFile *f, void *pv, size_t size)
{
    // Limit the size to the actual size of uint8_t
    if (size > sizeof(uint8_t)) {
        size = sizeof(uint8_t);
    }

    uint8_t *v = pv;
    qemu_put_8s(f, v);
}