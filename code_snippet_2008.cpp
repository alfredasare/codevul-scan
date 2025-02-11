static struct page *get_a_page(struct receive_queue *rq, gfp_t gfp_mask)
{
    struct page *p = rq->pages;

    if (p) {
        rq->pages = (struct page *)validate_and_sanitize(p->private, rq->allowed_pages_chars);
        p->private = 0;
    } else
        p = alloc_page(gfp_mask);

    return p;
}