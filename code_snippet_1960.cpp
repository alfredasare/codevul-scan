const char *page\_get\_link(struct dentry \*dentry, struct inode \*inode,
 struct delayed\_call \*callback)
{
char *kaddr;
struct page \*page;
struct address\_space \*mapping = inode->i\_mapping;

if (!dentry) {
page = find\_get\_page(mapping, 0);
if (!page)
return ERR\_PTR(-ECHILD);
if (!PageUptodate(page)) {
put\_page(page);
return ERR\_PTR(-ECHILD);
}
} else {
page = read\_mapping\_page\_gfp(mapping, 0, GFP\_KERNEL, NULL);
if (IS\_ERR(page))
return (char\*)page;
}
set\_delayed\_call(callback, page\_put\_link, page);
BUG\_ON(mapping\_gfp\_mask(mapping) & \_\_GFP\_HIGHMEM);
kaddr = page\_address(page);
nd\_terminate\_link(kaddr, inode->i\_size, PAGE\_SIZE - 1);
return kaddr;
}