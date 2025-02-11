int jpc_tsfb_analyze2(jpc_tsfb_t *tsfb, int *a, int xstart, int ystart,
                      int width, int height, int stride, int numlvls)
{
    // Validate input parameters
    if (width <= 0 || height <= 0 || xstart < 0 || ystart < 0 ||
        xstart + width > tsfb->img.x1 || ystart + height > tsfb->img.y1) {
        return -1;
    }

    if (width > 0 && height > 0) {
        if ((*tsfb->qmfb->analyze)(a, MIN(xstart + width, tsfb->img.x1),
                                   MIN(ystart + height, tsfb->img.y1),
                                   MIN(width, tsfb->img.x1 - xstart),
                                   MIN(height, tsfb->img.y1 - ystart), stride)) {
            return -1;
        }

        if (numlvls > 0) {
            if (jpc_tsfb_analyze2(tsfb, a, JPC_CEILDIVPOW2(xstart, 1),
                                   JPC_CEILDIVPOW2(ystart, 1),
                                   JPC_CEILDIVPOW2(xstart + width, 1) -
                                   JPC_CEILDIVPOW2(xstart, 1),
                                   JPC_CEILDIVPOW2(ystart + height, 1) -
                                   JPC_CEILDIVPOW2(ystart, 1), stride, numlvls - 1)) {
                return -1;
            }
        }
    }
    return 0;
}