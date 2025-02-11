static int rb_head_page_replace(struct buffer\_page \*old, struct buffer\_page \*new)
{
 struct list\_head *old\_next;
 unsigned long val;
 unsigned long ret;

 old\_next = old->list.prev;

 val = (unsigned long)old\_next & ~RB\_FLAG\_MASK;
 val |= RB\_PAGE\_HEAD;

 ret = cmpxchg(&old\_next->next, (unsigned long)old, (unsigned long)new);

 return ret == (unsigned long)old;
}