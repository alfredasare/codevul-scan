void vrend\_object\_bind\_dsa(struct vrend\_context \*ctx,
uint32\_t handle)
{
struct pipe\_depth\_stencil\_alpha\_state \*state;

if (handle == 0) {
memset(&ctx->sub->dsa\_state, 0, sizeof(ctx->sub->dsa\_state));
ctx->sub->dsa = NULL;
ctx->sub->stencil\_state\_dirty = true;
ctx->sub->shader\_dirty = true;
vrend\_hw\_emit\_dsa(ctx);
return;
}

state = vrend\_object\_lookup(ctx->sub->object\_hash, handle, VIRGL\_OBJECT\_DSA);
if (!state) {
report\_context\_error(ctx, VIRGL\_ERROR\_CTX\_ILLEGAL\_HANDLE, handle);
return;
}

if (ctx->sub->dsa != state) {
ctx->sub->stencil\_state\_dirty = true;
ctx->sub->shader\_dirty = true;
}

if (state != NULL) { // Add null check
ctx->sub->dsa\_state = *state;
ctx->sub->dsa = state;
}

vrend\_hw\_emit\_dsa(ctx);
}