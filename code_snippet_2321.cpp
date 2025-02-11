static av_cold int hevc\_init\_context(AVCodecContext \*avctx)
{
HEVCContext \*s = avctx->priv\_data;
int i;

s->avctx = avctx;

s->HEVClc = av\_mallocz(sizeof(HEVCLocalContext));
if (!s->HEVClc)
goto fail;
s->HEVClcList[0] = s->HEVClc;
s->sList[0] = s;

s->cabac\_state = av\_calloc(1, HEVC\_CONTEXTS);
if (!s->cabac\_state)
goto fail;

s->output\_frame = av\_frame\_alloc();
if (!s->output\_frame)
goto fail;

for (i = 0; i < FF\_ARRAY\_ELEMS(s->DPB); i++) {
s->DPB[i].frame = av\_frame\_alloc();
if (!s->DPB[i].frame)
goto fail;
s->DPB[i].tf.f = s->DPB[i].frame;
}

s->max\_ra = INT\_MAX;

s->md5\_ctx = av\_md5\_alloc();
if (!s->md5\_ctx)
goto fail;

ff\_bswapdsp\_init(&s->bdsp);

s->context\_initialized = 1;
s->eos = 0;

ff\_hevc\_reset\_sei(&s->sei);

return 0;

fail:
hevc\_decode\_free(avctx);
return AVERROR(ENOMEM);
}