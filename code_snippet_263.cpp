GF_Err moof_dump(GF_Box *a, FILE * trace)
{
    GF_MovieFragmentBox *p;
    p = (GF_MovieFragmentBox *)a;
    gf_isom_box_dump_start(a, "MovieFragmentBox", trace);
    int trackCount = gf_list_count(p->TrackList);
    fprintf(trace, "TrackFragments=\"%d\">\n", trackCount);
    if (p->mfhd) gf_isom_box_dump(p->mfhd, trace);
    for (int i = 0; i < trackCount; i++) {
        gf_isom_box_dump(p->TrackList[i], trace);
    }
    gf_isom_box_dump_done("MovieFragmentBox", a, trace);
    return GF_OK;
}