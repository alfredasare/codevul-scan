void vrend_object_bind_dsa(struct vrend_context *ctx, uint32_t handle) {
    struct pipe_depth_stencil_alpha_state *state;

    if (handle == 0) {
        //...
    } else {
        if (!vrend_object_exists(ctx->sub->object_hash, handle)) {
            report_context_error(ctx, VIRGL_ERROR_CTX_ILLEGAL_HANDLE, handle);
            return;
        }

        if (!vrend_object_has_permission(ctx->sub->object_hash, handle, VIRGL_PERMISSION_READ_WRITE)) {
            report_context_error(ctx, VIRGL_ERROR_CTX_ACCESS_DENIED, handle);
            return;
        }

        state = vrend_object_lookup(ctx->sub->object_hash, handle, VIRGL_OBJECT_DSA);
        if (!state) {
            //...
        }
        //...
    }
}