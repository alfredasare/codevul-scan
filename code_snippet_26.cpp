void vrend\_set\_blend\_color(struct vrend\_context \*ctx,
struct pipe\_blend\_color \*color)
{
if (color && sizeof(struct pipe\_blend\_color) <= sizeof(ctx->sub->blend\_color)) {
ctx->sub->blend\_color = *color;
glBlendColor(color->color[0], color->color[1], color->color[2],
color->color[3]);
}
}