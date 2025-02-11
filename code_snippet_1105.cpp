void comps_mrtree_clear(COMPS_MRTree * rt) {
    COMPS_HSListItem *it = NULL, *oldit;
    if (rt == NULL) return;
    if (rt->subnodes == NULL) return;
    oldit = rt->subnodes->first;
    if (oldit == NULL) return;
    for (;oldit!= NULL; oldit = it) {
        it = oldit->next;
        if (oldit!= NULL && rt->subnodes->data_destructor!= NULL)
            rt->subnodes->data_destructor(oldit->data);
        free(oldit);
    }
}