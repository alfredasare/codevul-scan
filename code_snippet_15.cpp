static int vrend_decode_set_stencil_ref(struct vrend_decode_ctx *ctx, int length)
{
   if (length!= VIRGL_SET_STENCIL_REF_SIZE)
      return EINVAL;

   struct pipe_stencil_ref ref;
   size_t val_size = get_buf_entry_size(ctx, VIRGL_SET_STENCIL_REF);
   size_t* val_ptr = (size_t*)malloc(val_size);
   if (!val_ptr)
      return ENOMEM;

   get_buf_entry(ctx, VIRGL_SET_STENCIL_REF, val_ptr, sizeof(size_t));

   ref.ref_value[0] = val_ptr[0] & 0xff;
   ref.ref_value[1] = (val_ptr[0] >> 8) & 0xff;
   vrend_set_stencil_ref(ctx->grctx, &ref);
   free(val_ptr);
   return 0;
}