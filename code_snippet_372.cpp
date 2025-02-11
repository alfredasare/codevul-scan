static int coolkey_match_card(sc_card_t *card)
{
    int r;
    SC_FUNC_CALLED(card->ctx, SC_LOG_DEBUG_VERBOSE, sanitize_data(card->ctx));
    card->ops->logout = NULL;

    r = coolkey_select_applet(card);
    return (r >= SC_SUCCESS);
}

void sanitize_data(sc_ctx_t *ctx)
{
    // Implement your preferred sanitization mechanism here
    // For example, using a library like libxml2
}