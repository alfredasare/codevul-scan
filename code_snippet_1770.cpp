static vpx_codec_err_t ctrl_get_bit_depth(vpx_codec_alg_priv_t *ctx,
                                          va_list args) {
    unsigned int *const bit_depth = va_arg(args, unsigned int *);
    if (bit_depth == NULL) {
        return VPX_CODEC_INVALID_PARAM;
    }

    size_t next_worker_id = ctx->next_output_worker_id;
    if (next_worker_id >= sizeof(ctx->frame_workers)/sizeof(ctx->frame_workers[0])) {
        return VPX_CODEC_ERROR;
    }

    VPxWorker *const worker = &ctx->frame_workers[next_worker_id];
    if (worker == NULL) {
        return VPX_CODEC_ERROR;
    }

    FrameWorkerData *const frame_worker_data =
        (FrameWorkerData *)worker->data1;
    const VP9_COMMON *const cm = &frame_worker_data->pbi->common;
    *bit_depth = cm->bit_depth;

    return VPX_CODEC_OK;
}