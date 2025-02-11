static long tun\_set\_vnet\_be(struct tun\_struct *tun, int __user \*argp)
{
 int be;

 if (!tun) {
 pr\_err("tun\_set\_vnet\_be: tun pointer is NULL\n");
 return -EINVAL;
 }

 if (get\_user(be, argp))
 return -EFAULT;

 if (be)
 tun->flags |= TUN\_VNET\_BE;
 else
 tun->flags &= ~TUN\_VNET\_BE;

 return 0;
}