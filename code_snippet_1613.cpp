void CSoundFile::UpdateTimeSignature()
{
    if(!Patterns.IsValidIndex(m_PlayState.m_nPattern))
    {
        m_PlayState.m_nCurrentRowsPerBeat = m_nDefaultRowsPerBeat;
        m_PlayState.m_nCurrentRowsPerMeasure = m_nDefaultRowsPerMeasure;
    }
    else if(m_PlayState.m_nPattern < 0 || m_PlayState.m_nPattern >= Patterns.size())
    {
        m_PlayState.m_nCurrentRowsPerBeat = m_nDefaultRowsPerBeat;
        m_PlayState.m_nCurrentRowsPerMeasure = m_nDefaultRowsPerMeasure;
    }
    else
    {
        m_PlayState.m_nCurrentRowsPerBeat = Patterns[m_PlayState.m_nPattern].GetRowsPerBeat();
        m_PlayState.m_nCurrentRowsPerMeasure = Patterns[m_PlayState.m_nPattern].GetRowsPerMeasure();
    }
}