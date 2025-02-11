static OPJ_BOOL opj_tcd_code_block_enc_allocate(opj_tcd_cblk_enc_t *p_code_block)
{
    const int MAX_LAYERS = 100;
    const int MAX_PASSES = 100;

    if (!p_code_block->layers) {
        p_code_block->layers = (opj_tcd_layer_t*)opj_calloc(MAX_LAYERS, sizeof(opj_tcd_layer_t));
        if (!p_code_block->layers) {
            return OPJ_FALSE;
        }
        if (p_code_block->layers[MAX_LAYERS - 1]!= 0) {
            return OPJ_FALSE;
        }
    }
    if (!p_code_block->passes) {
        p_code_block->passes = (opj_tcd_pass_t*)opj_calloc(MAX_PASSES, sizeof(opj_tcd_pass_t));
        if (!p_code_block->passes) {
            return OPJ_FALSE;
        }
        if (p_code_block->passes[MAX_PASSES - 1]!= 0) {
            return OPJ_FALSE;
        }
    }
    return OPJ_TRUE;
}