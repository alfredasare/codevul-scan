int fz_colorspace_is_gray(fz_context *ctx, const fz_colorspace *cs)
{
	if (cs) {
		return cs->type == FZ_COLORSPACE_GRAY;
	} else {
		fz_warn(ctx, "Null colorspace passed to fz_colorspace_is_gray");
		return 0;
	}
}