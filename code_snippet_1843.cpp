#include <duktape.h>

void js_dup(duk_context *ctx) {
    duk_copy(ctx, -1);
}