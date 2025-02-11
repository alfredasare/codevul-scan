c++
void CSoundFile::UpdateTimeSignature()
{
    if (m_PlayState.m_nPattern >= 0 && m_PlayState.m_nPattern < Patterns.Size())
    {
        if (Patterns[m_PlayState.m_nPattern].GetOverrideSignature())
        {
            m_PlayState.m_nCurrentRowsPerBeat = Patterns[m_PlayState.m_nPattern].GetRowsPerBeat();
            m_PlayState.m_nCurrentRowsPerMeasure = Patterns[m_PlayState.m_nPattern].GetRowsPerMeasure();
        }
        else
        {
            m_PlayState.m_nCurrentRowsPerBeat = m_nDefaultRowsPerBeat;
            m_PlayState.m_nCurrentRowsPerMeasure = m_nDefaultRowsPerMeasure;
        }
    }
    else
    {
        m_PlayState.m_nCurrentRowsPerBeat = m_nDefaultRowsPerBeat;
        m_PlayState.m_nCurrentRowsPerMeasure = m_nDefaultRowsPerMeasure;
    }
}