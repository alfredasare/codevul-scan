static int mov_read_moov(MOVContext *c, AVIOContext *pb, MOVAtom atom)
{
    int ret;

    if ((ret = mov_read_default(c, pb, atom, sizeof(c->atom_buffer))) < 0)
        return ret;
    c->found_moov=1;
    return 0; /* now go for mdat */
}