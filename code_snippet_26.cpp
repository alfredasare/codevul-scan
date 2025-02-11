void vrend_set_blend_color(struct vrend_context *ctx, struct pipe_blend_color *color) {
    if (color == NULL || color->color == NULL) {
        return;
    }

    if (color->color[0] < 0.0f || color->color[0] > 1.0f ||
        color->color[1] < 0.0f || color->color[1] > 1.0f ||
        color->color[2] < 0.0f || color->color[2] > 1.0f ||
        color->color[3] < 0.0f || color->color[3] > 1.0f) {
        return;
    }

    ctx->sub->blend_color = *color;
    glBlendColor(color->color[0], color->color[1], color->color[2], color->color[3]);
}