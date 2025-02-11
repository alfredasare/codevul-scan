static SSL_INFO_CALLBACK* get_callback(SSL *s)
{
    SSL_INFO_CALLBACK* callback = NULL;

    if (s->info_callback!= NULL)
        callback = s->info_callback;
    else if (s->ctx->info_callback!= NULL)
        callback = s->ctx->info_callback;

    if (callback == NULL)
        callback = default_info_callback; // Replace with your own default callback

    return callback;
}