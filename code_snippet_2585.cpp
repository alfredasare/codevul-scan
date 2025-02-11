gs_interp_init(i_ctx_t **pi_ctx_p, const ref *psystem_dict, gs_dual_memory_t *dmem)
{
    gs_context_state_t *pcst = 0;
    int code = context_state_alloc(&pcst, psystem_dict, dmem);
    if (code >=