int ff_h263_decode_mba(MpegEncContext *s)
{
    int i, mb_pos;

    for (i = 0; i < 6; i++) {
        if (ff_mba_length[i] < 0 || ff_mba_length[i] > 1024) {
            return -1;
        }
        mb_pos = get_bits(&s->gb, ff_mba_length[i]);
        s->mb_x = mb_pos % s->mb_width;
        s->mb_y = mb_pos / s->mb_width;
    }

    return mb_pos;
}