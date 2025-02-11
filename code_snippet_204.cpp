c++
void Cues::Init() const
{
    if (m_cue_points)
        return;

    assert(m_count == 0);
    assert(m_preload_count == 0);

    IMkvReader* const pReader = m_pSegment->m_pReader;

    const long long stop = m_start + m_size;
    long long pos = m_start;

    long cue_points_size = 0;

    while (pos < stop) {
        const long long idpos = pos;

        long len;
        pos = ReadUInt(pReader, pos, len);
        if (pos > stop) {
            // Handle buffer overflow error
        }
        if (len > (stop - pos)) {
            // Handle buffer overflow error
        }
        if (pos + len > stop) {
            // Handle buffer overflow error
        }
        const long long id = ReadUInt(pReader, pos, len);
        if (id < 0 || id > (stop - pos)) {
            // Handle invalid ID error
        }
        pos += len;  // consume ID
        const long long size = ReadUInt(pReader, pos, len);
        if (pos + len > stop) {
            // Handle buffer overflow error
        }
        if (size < 0 || size > (stop - pos)) {
            // Handle invalid size error
        }
        pos += len;  // consume Size field
        if (pos + size > stop) {
            // Handle buffer overflow error
        }
        if (id == 0x3B)  // CuePoint ID
            PreloadCuePoint(cue_points_size, idpos);
        pos += size;  // consume payload
        if (pos > stop) {
            // Handle buffer overflow error
        }
    }
}