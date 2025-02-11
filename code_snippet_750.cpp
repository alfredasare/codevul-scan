static void huge_pagevec_release(struct pagevec *__maybe_unused *pvec)
{
    if (!pagevec_empty(pvec))
    {
        int i;

        for (i = 0; i < pagevec_count(pvec); ++i)
            put_page(pvec->pages[i]);

        pagevec_reinit(pvec);
    }
}