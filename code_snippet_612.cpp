#define IW_OPTION_NAME_LEN 32

CWE_FIX(void) iw_set_option(struct iw_context *ctx, const char *name, const char *val)
{
	int i;

	if(val==NULL || val[0]=='\0') {
		val = "1";
	}

	if(!ctx->req.options) {
		ctx->req.options = iw_mallocz(ctx, IW_MAX_OPTIONS*sizeof(struct iw_option_struct));
		if(!ctx->req.options) return;
		ctx->req.options_numalloc = IW_MAX_OPTIONS;
		ctx->req.options_count = 0;
	}

	for(i=0; i<ctx->req.options_count; i++) {
		if(ctx->req.options[i].name && !strcmp(ctx->req.options[i].name, name)) {
			iw_free(ctx, ctx->req.options[i].val);
			if (strlen(val) >= IW_OPTION_VALUE_LEN) {
				/* Handle error condition */
				return;
			}
			ctx->req.options[i].val = iw_mallocz(ctx, IW_OPTION_VALUE_LEN);
			if(!ctx->req.options[i].val) return;
			strlcpy(ctx->req.options[i].val, val, IW_OPTION_VALUE_LEN);
			return;
		}
	}

	if(ctx->req.options_count>=IW_MAX_OPTIONS) return;
	ctx->req.options[ctx->req.options_count].name = iw_mallocz(ctx, IW_OPTION_NAME_LEN);
	if(!ctx->req.options[ctx->req.options_count].name) return;
	if (strlen(name) >= IW_OPTION_NAME_LEN) {
		/* Handle error condition */
		return;
	}
	strlcpy(ctx->req.options[ctx->req.options_count].name, name, IW_OPTION_NAME_LEN);
	ctx->req.options[ctx->req.options_count].val = iw_mallocz(ctx, IW_OPTION_VALUE_LEN);
	if(!ctx->req.options[ctx->req.options_count].val) return;
	ctx->req.options_count++;
}