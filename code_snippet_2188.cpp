int equalizer_reset(effect_context_t *context)
{
    equalizer_context_t *eq_ctxt = (equalizer_context_t *)context;

    // Reset the equalizer context
    memset(eq_ctxt,