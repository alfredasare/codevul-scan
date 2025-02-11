static void image_ctx_free(ImageContext *img)
{
    int i, j;

    // Validate and sanitize huffman_groups array
    for (i = 0; i < img->nb_huffman_groups; i++) {
        const char *path = img->huffman_groups[i * HUFFMAN_CODES_PER_META_CODE + j].vlc;
        if (!is_valid_path(path) ||!is_allowed_directory(path)) {
            av_log(img, AV_LOG_ERROR, "Invalid or unauthorized path '%s'\n", path);
            return;
        }
    }

    // Free resources
    av_free(img->color_cache);
    if (img->role!= IMAGE_ROLE_ARGB &&!img->is_alpha_primary)
        av_frame_free(&img->frame);
    if (img->huffman_groups) {
        for (i = 0; i < img->nb_huffman_groups; i++) {
            for (j = 0; j < HUFFMAN_CODES_PER_META_CODE; j++)
                ff_free_vlc(&img->huffman_groups[i * HUFFMAN_CODES_PER_META_CODE + j].vlc);
        }
        av_free(img->huffman_groups);
    }
    memset(img, 0, sizeof(*img));
}