static int tg3_set_rxfh_indir(struct net\_device *dev, const u32 \*indir)
{
 struct tg3 \*tp = netdev\_priv(dev);
 size\_t i;

 if (indir == NULL || copy\_from\_user(&tp->rss\_ind\_tbl, indir, sizeof(u32) \* TG3\_RSS\_INDIR\_TBL\_SIZE)) {
 return -EFAULT;
 }

 if (!netif\_running(dev) || !tg3\_flag(tp, ENABLE\_RSS))
 return 0;

 tg3\_full\_lock(tp, 0);
 tg3\_rss\_write\_indir\_tbl(tp);
 tg3\_full\_unlock(tp);

 return 0;
}

This fix ensures input validation by checking if the 'indir' pointer is NULL and using 'copy\_from\_user()' to safely copy the data from user space. The loop and size checks have been removed since 'copy\_from\_user()' will handle the data copy and boundary checks.