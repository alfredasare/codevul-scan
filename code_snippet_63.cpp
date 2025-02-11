BN_ULONG bn_sub_words(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b, int n)
{
    BN_ULONG t1, t2;
    int c = 0;

    if (n <= 0) return (BN_ULONG)0;

    for (;;) {
        t1 = a[0] - b[0] - c;
        if (t1 >= 0) c = 0;
        else {
            t1 += BN_MASK2;
            c = 1;
        }
        r[0] = t1 & BN_MASK2;
        if (--n <= 0) break;

        t1 = a[1] - b[1] - c;
        if (t1 >= 0) c = 0;
        else {
            t1 += BN_MASK2;
            c = 1;
        }
        r[1] = t1 & BN_MASK2;
        if (--n <= 0) break;

        t1 = a[2] - b[2] - c;
        if (t1 >= 0) c = 0;
        else {
            t1 += BN_MASK2;
            c = 1;
        }
        r[2] = t1 & BN_MASK2;
        if (--n <= 0) break;

        a += 4;
        b += 4;
        r += 4;
    }
    return c;
}