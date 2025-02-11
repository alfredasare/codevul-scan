void free\_xenballooned\_pages(int nr\_pages, struct page **pages)
{
 int i;

 mutex\_lock(&balloon\_mutex);

 for (i = 0; i < nr\_pages; i++) {
 if (pages[i] != NULL) { // add null check
 __SetPageOffline(pages[i]);
 balloon\_append(pages[i]);
 }
 }

 balloon\_stats.target\_unpopulated -= nr\_pages;

 /* The balloon may be too large now. Shrink it if needed. */
 if (current\_credit())
 schedule\_delayed\_work(&balloon\_worker, 0);

 mutex\_unlock(&balloon\_mutex);
}