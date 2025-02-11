static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongSlong(int32 value)
{
    if (value < INT32_MIN || value > INT32_MAX)
    {
        return(TIFFReadDirEntryErrRange);
    }
    else
    {
        return(TIFFReadDirEntryErrOk);
    }
}