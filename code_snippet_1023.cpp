static void correctstack(lua_State *L, TValue *oldstack) {
> ptrdiff\_t diff = (char*)L->top - (char*)oldstack;
L->top += diff;
for (GCObject *up = L->openupval; up != NULL; up = up->gch.next)
gco2uv(up)->v += diff;
for (CallInfo *ci = L->base\_ci; ci <= L->ci; ci++) {
ci->top += diff;
ci->base += diff;
ci->func += diff;
}
L->base += diff;
}