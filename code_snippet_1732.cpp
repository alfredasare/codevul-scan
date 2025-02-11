static int mov_read_mdat(MOVContext *c, AVIOContext *pb, MOVAtom atom) {
    if (atom.size > 0 && atom.size <= INT_MAX) {
        c->found_mdat = 1;
        return 0;
    } else {
        return -1; // or some other error code
    }
}