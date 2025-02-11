#define MAX_NAME_LENGTH 256

struct dns_srvrq *find_srvrq_by_name(const char *name, struct proxy *px)
{
	struct dns_srvrq *srvrq;
	size_t name_len = strnlen(name, MAX_NAME_LENGTH);

	list_for_each_entry(srvrq, &dns_srvrq_list, list) {
		if (srvrq->proxy == px && name_len == strlen(srvrq->name) &&
		    memcmp(srvrq->name, name, name_len) == 0)
			return srvrq;
	}
	return NULL;
}