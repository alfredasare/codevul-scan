void grubfs_bind_io(RIOBind *iob, ut64 _delta) {
    bio = iob;
    delta = _delta;

    if (iob->size >= sizeof(ut64)) {
        memcpy(iob->buffer, &_delta, sizeof(ut64));
    } else {
        printf("Error: Buffer too small\n");
    }
}