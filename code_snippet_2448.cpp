WORD32 ihevcd_delete(iv_obj_t *ps_codec_obj, void *pv_api_op)
{
codec_t *ps_dec;
ihevcd_cxa_delete_op_t *ps_op = (ihevcd_cxa_delete_op_t *)pv_api_op;

ps_dec = (codec_t *)(ps_codec_obj->pv_codec_handle);
ps_op->s\_ivd\_delete\_op\_t.u4\_error\_code = 0;
ihevcd_free_dynamic_bufs(ps_dec);
ihevcd_free_static_bufs(ps_codec_obj);
return IV\_SUCCESS;
}