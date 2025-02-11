void comps_mrtree_clear_fixed(COMPS_MRTree * rt) {
    COMPS_HSListItem *item, *temp_node;
    if (rt == NULL || rt->subnodes == NULL) return;
    item = rt->subnodes->first;
    for (; item != NULL; ) {
        temp_node = item;
        item = item->next;
        if (rt->subnodes->data_destructor != NULL)
            rt->subnodes->data_destructor(temp_node->data);
        free(temp_node);
    }
}