int equalizer_reset(effect_context_t *context)
{
    equalizer_context_t *eq_ctxt = (equalizer_context_t *)context;

    if (!eq_ctxt) {
        LOG_ERROR("Invalid context pointer");
        return -EINVAL;
    }

    return 0;
}