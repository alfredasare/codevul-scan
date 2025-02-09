static void iwbmp_set_default_bitfields(struct iwbmprcontext *rctx)
{
	int k;

	if(rctx->bitfields_set) return;

	if(rctx->bitcount==16) {
		rctx->bf_mask[0]=0x7c00; // 01111100 00000000 (red)
		rctx->bf_mask[1]=0x03e0; // 00000011 11100000 (green)
		rctx->bf_mask[2]=0x001f; // 00000000 00011111 (blue)
	}
	else if(rctx->bitcount==32) {
		rctx->bf_mask[0]=0x00ff0000;
		rctx->bf_mask[1]=0x0000ff00;
		rctx->bf_mask[2]=0x000000ff;
	}
	else {
		return;
	}

	for(k=0;k<3;k++) {
		process_bf_mask(rctx,k);
	}
}
