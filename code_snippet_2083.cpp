fpDiff(TIFF* tif, uint8* cp0, tmsize_t cc)
{
	tmsize_t stride = PredictorState(tif)->stride;
	uint32 bps = tif->tif_dir.td_bitspersample / 8;
	tmsize_t wc = cc / bps;
	tmsize_t count;
	uint8 *cp = (uint8 *) cp0;
	uint8 *tmp = (uint8 *)_TIFFmalloc(cc);

	assert((cc%(bps*stride))==0);
	if (!tmp)
		return;

	_TIFFmemcpy(tmp, cp0, cc);
	for (count = 0; count < wc; count++) {
		uint32 byte;
		for (byte = 0; byte < bps; byte++) {
			#if WORDS_BIGENDIAN
			cp[byte * wc + count] = tmp[bps * count + byte];
			#else
			cp[(bps - byte - 1) * wc + count] =
				tmp[bps * count + byte];
			#endif
		}
	}
	_TIFFfree(tmp);

	cp = (uint8 *) cp0;
	cp += cc - stride - 1;
	for (count = cc; count > stride; count -= stride) {
		int32_t diff = (int32_t)(cp[0]);
		if (diff > 0) {
			if (count - stride <= diff) {
				continue;
			}
			diff = count - stride;
		} else if (diff < 0) {
			if (-diff >= count) {
				continue;
			}
		}
		REPEAT4(stride, cp[stride] = (unsigned char)((cp[stride] - cp[0])&0xff); cp--)
	}
}