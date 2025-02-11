#define MAX_TX_CANDIDATES_SIZE 1000 // Define this value according to your system's specifications.

static inline bool RuleMatchCandidateTxArrayHasSpace(const DetectEngineThreadCtx *det_ctx,
                                                       const uint32_t need)
{
    if ((det_ctx->tx_candidates_size >= need) && (need <= MAX_TX_CANDIDATES_SIZE))
        return 1;
    return 0;
}