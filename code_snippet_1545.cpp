void xmlattr_cleanup(struct xmlattr_list *list) {
    struct xmlattr *attr, *next;

    if (list == NULL || list->first == NULL) {
        return;
    }

    attr = list->first;
    while (attr!= NULL) {
        next = attr->next;
        free(attr->name);
        free(attr->value);
        free(attr);
        attr = next;
    }
    list->first = NULL;
    list->last = &(list->first);
}