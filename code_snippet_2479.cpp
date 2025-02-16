c++
static void ConvertLoopSlice(ModSample &src, ModSample &dest, SmpLength start, SmpLength len, bool loop)
{
    if(!src.HasSampleData()) return;

    dest.FreeSample();
    dest = src;
    SmpLength newLen = std::min(len, dest.nLength);
    dest.nLength = newLen;
    dest.pSample = nullptr;

    if(!dest.AllocateSample())
    {
        return;
    }

    if(len != src.nLength)
        MemsetZero(dest.cues);

    std::memcpy(dest.pSample8, src.pSample8 + start, newLen);
    dest.uFlags.set(CHN_LOOP, loop);
    if(loop)
    {
        dest.nLoopStart = 0;
        dest.nLoopEnd = newLen;
    } else
    {
        dest.nLoopStart = 0;
        dest.nLoopEnd = 0;
    }
}