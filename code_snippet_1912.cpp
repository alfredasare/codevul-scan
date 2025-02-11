assegment\_append\_asns (struct assegment \*seg, as\_t \*asnos, int num)
{
 as\_t \*newas;
 size\_t new\_size;

 new\_size = seg->length + num \* sizeof(as\_t);
 if (new\_size > ASSEGMENT\_DATA\_SIZE(seg->length, 1))
 {
 newas = XREALLOC (MTYPE\_AS\_SEG\_DATA, seg->as, new\_size);

if (newas)
{
seg->as = newas;
memcpy(seg->as + seg->length, asnos, num \* sizeof(as\_t));
seg->length = new\_size / sizeof(as\_t);
return seg;
}
}

assegment\_free\_all(seg);
return NULL;
}