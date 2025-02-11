static inline bool* RuleMatchCandidateTxArrayHasSpace(const DetectEngineThreadCtx *det_ctx, const uint32_t need) {
    if (det_ctx->tx_candidates_size >= need) {
        return NULL;  // Return NULL to indicate success
    }
    return (bool*)ERR_PTR(-EINVAL);  // Return error value to indicate failure
}