void nsc_context_free(NSC_CONTEXT* context)
{
    size_t i;
    size_t num_plane_buffers;

    if (!context)
        return;

    if (context->priv)
    {
        num_plane_buffers = context->priv->num_plane_buffers;
        for (i = 0; i < num_plane_buffers; i++)
            free(context->priv->PlaneBuffers[i]);

        BufferPool_Free(context->priv->PlanePool);
        nsc_profiler_print(context->priv);
        PROFILER_FREE(context->priv->prof_nsc_rle_decompress_data);
        PROFILER_FREE(context->priv->prof_nsc_decode);
        PROFILER_FREE(context->priv->prof_nsc_rle_compress_data);
        PROFILER_FREE(context->priv->prof_nsc_encode);
        free(context->priv);
    }

    free(context->BitmapData);
    free(context);
}