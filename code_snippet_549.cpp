static IW_INLINE unsigned int get_raw_sample_16(struct iw_context *ctx, int x, int y, int channel)
{
    size_t z;
    unsigned short tmpui16;

    if (x < 0 || y < 0 || channel < 0 || channel >= ctx->img1_numchannels_physical)
        return 0;
    z = y * ctx->img1.bpr + (ctx->img1_numchannels_physical * x + channel) * 2;
    if (z >= ctx->img1.size)
        return 0;
    tmpui16 = *(unsigned short*)((char*)ctx->img1.pixels + z);
    return tmpui16;
}