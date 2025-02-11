static inline void restore_ac_coeffs(MpegEncContext *s, int16_t block[6][64],
                                 const int dir[6], uint8_t *st[6],
                                 const int zigzag_last_index[6])
{
    int i, n;

    // Check if the size of the destination array is sufficient
    if (sizeof(s->block_last_index) >= sizeof(zigzag_last_index)) {
        memcpy(s->block_last_index, zigzag_last_index, sizeof(int) * 6);
    } else {
        // Handle error or limit the copying based on the actual size
        // For demonstration purposes, returning an error value is shown here
        return -1;
    }

    for (n = 0; n < 6; n++) {
        int16_t *ac_val = s->ac_val[0][0] + s->block_index[n] * 16;

        st[n] = s->intra_scantable.permutated;
        if (dir[n]) {
            /* top prediction */
            for (i = 1; i < 8; i++)
                block[n][s->idsp.idct_permutation[i]] = ac_val[i + 8];
        } else {
            /* left prediction */
            for (i = 1; i < 8; i++)
                block[n][s->idsp.idct_permutation[i << 3]] = ac_val[i];
        }
    }
}