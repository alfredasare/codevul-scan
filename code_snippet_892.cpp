static void correctstack(lua_State *L, TValue *oldstack) {
  CallInfo *ci;
  GCObject *up;
  size_t stack_size = L->stack - L->top;
  L->top = (L->top - oldstack) + L->stack;
  for (up = L->openupval; up!= NULL; up = up->gch.next) {
    gco2uv(up)->v = (gco2uv(up)->v - oldstack) + L->stack;
    if (gco2uv(up)->v > L->stack) {
      // Handle buffer overflow error
    }
  }
  for (ci = L->base_ci; ci <= L->ci; ci++) {
    ci->top = (ci->top - oldstack) + L->stack;
    ci->base = (ci->base - oldstack) + L->stack;
    ci->func = (ci->func - oldstack) + L->stack;
    if (ci->top > L->stack) {
      // Handle buffer overflow error
    }
  }
  L->base = (L->base - oldstack) + L->stack;
}