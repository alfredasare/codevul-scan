static void get_futex_key_refs(union futex_key *key)
{
    if (!key->both.ptr)
        return;

    //... (rest of the code remains the same)

    switch (key->both.offset & (FUT_OFF_INODE|FUT_OFF_MMSHARED)) {
        case FUT_OFF_INODE:
            if (key->both.offset < 0 || key->both.offset > FUT_MAX_INODE_OFFSET) {
                // Handle invalid offset
            } else {
                ihold(key->shared.inode); /* implies smp_mb(); (B) */
            }
            break;
        case FUT_OFF_MMSHARED:
            if (key->both.offset < 0 || key->both.offset > FUT_MAX_MMSHARED_OFFSET) {
                // Handle invalid offset
            } else {
                futex_get_mm(key); /* implies smp_mb(); (B) */
            }
            break;
        default:
            //... (rest of the code remains the same)
    }
}