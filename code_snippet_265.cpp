GF_Err moof\_dump(GF\_Box \*a, FILE \* trace)
{
 if (!a || !trace) return GF\_BAD\_PARAM;
 GF\_MovieFragmentBox \*p;
 p = (GF\_MovieFragmentBox \*)a;
 gf\_isom\_box\_dump\_start(a, "MovieFragmentBox", trace);
 fprintf(trace, "TrackFragments=\"%d\">\n", gf\_list\_count(p->TrackList));
 if (p->mfhd && p->mfhd->size<=GF\_ISOM\_BOX\_SIZE\_LIMIT) //limit box size
 gf\_isom\_box\_dump(p->mfhd, trace);
 gf\_isom\_box\_array\_dump(p->TrackList, trace);
 gf\_isom\_box\_dump\_done("MovieFragmentBox", a, trace);
 return GF\_OK;
}