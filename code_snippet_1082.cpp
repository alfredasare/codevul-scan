Here's the fixed version of the code:


evdns_resolv_set_defaults(struct evdns_base *base, int flags) {
	const int valid_flags[] = {DNS_OPTION_SEARCH, DNS_OPTION_NAMESERVERS};
	int i;

	ASSERT_LOCKED(base);

	for (i = 0; i < sizeof(valid_flags)/sizeof(int); i++) {
		if (flags & (1 << valid_flags[i])) {
			switch (valid_flags[i]) {
				case DNS_OPTION_SEARCH:
					search_set_from_hostname(base);
					break;