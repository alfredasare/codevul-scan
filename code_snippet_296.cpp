int av_get_audio_frame_duration(AVCodecContext *avctx, int frame_bytes)
{
    int duration = 0;

    if (avctx == NULL || frame_bytes < 0) {
        return -1; // Invalid input
    }

    duration = (avctx->sample_rate * avctx->channels * avctx->block_align * avctx->bits_per_coded_sample) / avctx->bit_rate;

    return duration;
}