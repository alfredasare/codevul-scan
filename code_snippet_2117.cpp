static struct page *get\_a\_page(struct receive\_queue \*rq, gfp\_t gfp\_mask)
{
 struct page *next\_page, *p = rq->pages;

 if (p) {
 next\_page = (struct page \*)p->private;
 /* clear private here, it is used to chain pages */
 p->private = 0;
 rq->pages = next\_page;
 } else
 p = alloc\_page(gfp\_mask);
 return p;
}