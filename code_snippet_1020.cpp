void WT_UpdateLFO (S_LFO_CONTROL *pLFO, EAS_I16 phaseInc)
{
    /* Check if pLFO->lfoPhase is within the valid range */
    if (pLFO->lfoPhase < -0x7fff || pLFO->lfoPhase > 0x7fff) {
        /* Handle out-of-range values, e.g., clamp or error */
        pLFO->lfoPhase = (pLFO->lfoPhase % 0x8000); 
    }
    if (pLFO->lfoPhase < 0)
    {
        pLFO->lfoPhase++;
    }
    pLFO->lfoValue = (EAS_I16) (pLFO->lfoPhase << 2);
    if ((pLFO->lfoPhase > 0x1fff) && (pLFO->lfoPhase < 0x6000))
        pLFO->lfoValue = ~pLFO->lfoValue;
    pLFO->lfoPhase = (pLFO->lfoPhase + phaseInc) & 0x7fff;
}