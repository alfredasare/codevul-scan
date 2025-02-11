static void \*igmp\_mc\_seq\_next(struct seq\_file \*seq, void \*v, loff\_t \*pos)
{
 struct ip\_mc\_list \*im;
 if (v == SEQ\_START\_TOKEN)
 im = igmp\_mc\_get\_first(seq);
 else {
 if (\*pos >= igmp\_mc\_count(seq))
 return NULL;
 im = igmp\_mc\_get\_next(seq, v);
 }
 ++\*pos;
 return im;
}