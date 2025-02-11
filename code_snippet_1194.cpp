void WT\_UpdateLFO(S\_LFO\_CONTROL \*pLFO, EAS\_I16 phaseInc)
{
if (pLFO->lfoPhase < 0)
{
pLFO->lfoPhase++;
return;
}

pLFO->lfoValue = (EAS\_I16)(pLFO->lfoPhase << 2);

if ((pLFO->lfoPhase > 0x1fff) && (pLFO->lfoPhase < 0x6000))
pLFO->lfoValue = ~pLFO->lfoValue;

pLFO->lfoPhase = SafeInt<uint16\_t>::Add(pLFO->lfoPhase, phaseInc);
}

#include <SafeInt.h>