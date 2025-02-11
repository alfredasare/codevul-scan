struct dns_srvrq *find_srvrq_by_name(const char *name, struct proxy *px)
{
    struct dns_srvrq *srvrq = NULL;
    struct dns_srvrq *tmp;

    list_for_each_entry(tmp, &dns_srvrq_list, list) {
        if (tmp && tmp->proxy == px &&!strcmp(tmp->name, name)) {
            srvrq = tmp;
            break;
        }
    }

    return srvrq;
}