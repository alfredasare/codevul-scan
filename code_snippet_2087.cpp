static av_cold int hevc_init_context(AVCodecContext *avctx)
{
    HEVCContext *s = avctx->priv_data;
    int i;

    s->avctx = avctx;

    s->HEVClc = av_mallocz(sizeof(HEVCLocalContext));
    if (!s->HEVClc) {
        av_free(s->HEVClc);
        return AVERROR(ENOMEM);
    }
    s->HEVClcList[0] = s->HEVClc;
    s->sList[0] = s;

    s->cabac_state = av_malloc(HEVC_CONTEXTS);
    if (!s->cabac_state) {
        av_free(s->HEVClc);
        return AVERROR(ENOMEM);
    }

    s->output_frame = av_frame_alloc();
    if (!s->output_frame) {
        av_free(s->HEVClc);
        av_free(s->cabac_state);
        return AVERROR(ENOMEM);
    }

    for (i = 0; i < FF_ARRAY_ELEMS(s->DPB); i++) {
        s->DPB[i].frame = av_frame_alloc();
        if (!s->DPB[i].frame) {
            for (int j = 0; j < i; j++) {
                av_frame_free(&s->DPB[j].frame);
            }
            av_free(s->HEVClc);
            av_free(s->cabac_state);
            av_frame_free(&s->output_frame);
            return AVERROR(ENOMEM);
        }
        s->DPB[i].tf.f = s->DPB[i].frame;
    }

    s->max_ra = INT_MAX;

    s->md5_ctx = av_md5_alloc();
    if (!s->md5_ctx) {
        for (int j = 0; j < FF_ARRAY_ELEMS(s->DPB); j++) {
            av_frame_free(&s->DPB[j].frame);
        }
        av_free(s->HEVClc);
        av_free(s->cabac_state);
        av_frame_free(&s->output_frame);
        return AVERROR(ENOMEM);
    }

    ff_bswapdsp_init(&s->bdsp);

    s->context_initialized = 1;
    s->eos = 0;

    ff_hevc_reset_sei(&s->sei);

    return 0;
}