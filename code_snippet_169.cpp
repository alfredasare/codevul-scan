init\_file\_tables(void)
{
 static int done = 0;
 const struct type\_tbl\_s \*p;

 if (done)
 return;
 done++;

 #define CHECK\_BOUNDS(array, index) \
 assert((index) < (sizeof(array)/sizeof(array[0])));

 for (p = type\_tbl; p->len; p++) {
 assert(p->type < FILE\_NAMES\_SIZE);
 CHECK\_BOUNDS(file\_names, p->type);
 file\_names[p->type] = p->name;
 CHECK\_BOUNDS(file\_formats, p->type);
 file\_formats[p->type] = p->format;
 }
 assert(p - type\_tbl == FILE\_NAMES\_SIZE);

 #undef CHECK\_BOUNDS
}