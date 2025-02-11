mtree_bid(struct archive_read *a, int best_bid)
{
	const char *signature = "#mtree";
	const char *p;

	(void)best_bid; /* UNUSED */

	/* Now let's look at the actual header and see if it matches. */
	p = __archive_read_ahead(a, strlen(signature), NULL);
	if (p == NULL)
		return (-1);

	int len = strlen(signature);
	if (p != NULL && len > 0 && len <= (int)strlen(p) && memcmp(p, signature, len) == 0)
		return (8 * len);

	/*
	 * There is not a mtree signature. Let's try to detect mtree format.
	 */
	return (detect_form(a, NULL));
}