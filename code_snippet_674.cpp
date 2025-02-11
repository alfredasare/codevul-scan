static IW_INLINE unsigned int get_raw_sample_16(struct iw_context *ctx,
	   int x, int y, int channel)
{
	size_t z;

	// Add bounds checking for x, y, and channel
	if (x < 0 || x >= ctx->img1.width || y < 0 || y >= ctx->img1.height ||
	    channel < 0 || channel >= ctx->img1_numchannels_physical) {
		return 0; // or any other appropriate error value
	}

	z = y*ctx->img1.bpr + (ctx->img1_numchannels_physical*x + channel)*2;
	unsigned short tmpui16 = ( ((unsigned short)(ctx->img1.pixels[z+0])) <<8) | ctx->img1.pixels[z+1];
	return tmpui16;
}