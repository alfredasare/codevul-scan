int rosecmpm(rose_address *addr1, rose_address *addr2, unsigned short mask)
{
    static const unsigned short MAX_MASK = USHRT_MAX;

    if (mask > MAX_MASK)
        return 1;

    for (unsigned short i = 0; i < mask; i++) {
        //...
    }

    return 0;
}