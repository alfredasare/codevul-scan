static info_cb get_callback(SSL *s)
{
    if (s == NULL || s->info_callback == NULL)
        return NULL;
    
    if (s->ctx && s->ctx->info_callback != NULL)
        return s->ctx->info_callback;
    
    return s->info_callback;
}