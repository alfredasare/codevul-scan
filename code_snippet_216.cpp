static void SSL\_SESSION\_list\_add(SSL\_CTX *ctx, SSL\_SESSION *s)
{
if (CRYPTO\_Mutex\_lock(ctx->lock)) /* Lock the mutex before modification */
{
if ((s->next != NULL) && (s->prev != NULL))
SSL\_SESSION\_list\_remove(ctx, s);

if (ctx->session\_cache\_head == NULL) {
ctx->session\_cache\_head = s;
ctx->session\_cache\_tail = s;
s->prev = (SSL\_SESSION *) &(ctx->session\_cache\_head);
s->next = (SSL\_SESSION *) &(ctx->session\_cache\_tail);
} else {
s->next = ctx->session\_cache\_head;
s->next->prev = s;
s->prev = (SSL\_SESSION *) &(ctx->session\_cache\_head);
ctx->session\_cache\_head = s;
}
}
CRYPTO\_Mutex\_unlock(ctx->lock); /* Unlock the mutex after modification */
}