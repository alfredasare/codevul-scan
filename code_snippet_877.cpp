static void huge_pagevec_release(struct pagevec *pvec)
{
	if (!pvec)
		return;

	int i;

	for (i = 0; i < pagevec_count(pvec); ++i) {
		if (!pvec->pages[i])
			continue;
		put_page(pvec->pages[i]);
	}

	pagevec_reinit(pvec);
}