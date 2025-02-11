cl\_block(GifCtx \*ctx) \[{\{\{*/ table clear for block compress \*/\}\}\]
{
cl\_hash((count\_int) hsize, ctx);
ctx->free\_ent = ctx->ClearCode + 2;
ctx->clear\_flg = 1;

if(ctx->ClearCode < MAX\_CODE) {
output((code\_int)ctx->ClearCode, ctx);
}
}