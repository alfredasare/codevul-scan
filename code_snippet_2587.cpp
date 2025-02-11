int dodynamic(struct magic_set *ms, void *vbuf, size_t offset, size_t size,
              int clazz, int swap)
{
    if (vbuf == NULL || size < offset + xdh_sizeof) {
        return -1;
    }

    Elf32_Dyn dh32;
    Elf64_Dyn dh64;
    unsigned char *dbuf = CAST(unsigned char *, vbuf);

    if (xdh_sizeof + offset > size) {
        return xdh_sizeof + offset;
    }

    memcpy(xdh_addr, &dbuf[offset], xdh_sizeof);
    offset += xdh_sizeof;

    switch (xdh_tag) {
    case DT_FLAGS_1:
        if (xdh_val == DF_1_PIE)
            ms->mode |= 0111;
        else
            ms->mode &= ~0111;
        break;
    default:
        break;
    }
    return offset;
}