int av_get_audio_frame_duration(AVCodecContext *avctx, int frame\_bytes)
{
int max\_frame\_bytes = avctx->frame\_size \* avctx->channels \* avctx->bits\_per\_coded\_sample / 8;
if (frame\_bytes > max\_frame\_bytes)
frame\_bytes = max\_frame\_bytes;
return get\_audio\_frame\_duration(avctx->codec\_id, avctx->sample\_rate,
avctx->channels, avctx->block\_align,
avctx->codec\_tag, avctx->bits\_per\_coded\_sample,
avctx->bit\_rate, avctx->extradata, avctx->frame\_size,
frame\_bytes);
}