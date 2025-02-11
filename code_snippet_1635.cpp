void nsc_encode(NSC_CONTEXT* context, const BYTE* bmpdata, UINT32 rowstride) {
    nsc_encode_argb_to_aycocg(context, bmpdata, rowstride);

    if (context->ChromaSubsamplingLevel) {
        nsc_encode_subsampling(context);
    }

    nsc_free_context(context);
}

void nsc_free_context(NSC_CONTEXT* context) {
    context->ChromaSubsamplingLevel = 0;
    memset(context, 0, sizeof(NSC_CONTEXT));
}