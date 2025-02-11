void Cues::Init() const
{
if (m\_cue\_points)
return;
 assert(m\_count == 0);
 assert(m\_preload\_count == 0);
 IMkvReader\* const pReader = m\_pSegment->m\_pReader;
 const long long stop = m\_start + m\_size;
 long long pos = m\_start;
 long cue\_points\_size = 0;
 while (pos < stop)
 {
const long long idpos = pos;
long len = sizeof(long long); // Defined length for safety
if (pos + len > stop) // Check for boundary
break;
long long id = ReadUInt(pReader, pos, len);
pos += len; //consume ID
len = sizeof(long long); // Defined length for safety
if (pos + len > stop) // Check for boundary
break;
long long size = ReadUInt(pReader, pos, len);
pos += len; //consume Size field
if (id == 0x3B) //CuePoint ID
PreloadCuePoint(cue\_points\_size, idpos);
len = size; // Defined length for safety
if (pos + len > stop) // Check for boundary
break;
pos += size; //consume payload
assert(pos <= stop);
}
}