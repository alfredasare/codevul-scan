static int __f2fs\_commit\_super(struct buffer\_head \*bh,
 struct f2fs\_super\_block \*super)
{
 lock\_buffer(bh);
 if (super) {
 if (copy\_from\_user\_overlap(bh->b\_data + F2FS\_SUPER\_OFFSET, super, sizeof(\*super))) {
 unlock\_buffer(bh);
 return -EFAULT;
 }
 }
 set\_buffer\_uptodate(bh);
 set\_buffer\_dirty(bh);
 unlock\_buffer(bh);

 /* it's rare case, we can do fua all the time */
 return __sync\_dirty\_buffer(bh, REQ\_SYNC | REQ\_PREFLUSH | REQ\_FUA);
}